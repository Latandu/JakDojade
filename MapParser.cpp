//
// Created by Latandu on 25/04/2023.
//

#include "MapParser.h"
#include "String.h"
#include "BFS.h"
#include "Dijkstra.h"
#include <iostream>
MapParser::MapParser() {
    String wS;
    String hS;
    while((c = (char)getchar()) != ' '){
        wS.AddChar(c);
    }
    w = wS.StringToIntConversion();
    while((c = (char)getchar()) != '\n'){
        hS.AddChar(c);
    }
    h = hS.StringToIntConversion();
    mapArray = new char*[h] ;
    for(int i = 0; i < h; i++){
        mapArray[i] = new char[w];
    }

}
bool MapParser::CitySearch(int row, int column){
    int newRow, newCol;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;
             newRow = row + i;
             newCol = column + j;
            if (newRow >= 0 && newRow < h && newCol >= 0 && newCol < w) {
                int newChar = (int)(unsigned char)mapArray[newRow][newCol];
                if((ASCII_0 <= newChar && newChar <= ASCII_9) || (ASCII_A <= newChar && newChar <= ASCII_Z)){
                    ParseCity(newRow, newCol, row,column);
                    return true;
                }
            }
        }
    } return false;

}
void MapParser::ParseCity(int row, int column, int starPointX, int starPointY){
    static int cityID = 0;
    int RowN = starPointX;
    int ColN = starPointY;
    auto *newString = new String;
    bool wentThrough = false;
    int newChar = (int)(unsigned char)mapArray[row][column];
    while(column > 0 && ((ASCII_0 <= newChar && newChar <= ASCII_9) || (ASCII_A <= newChar && newChar <= ASCII_Z))){
        column--;
        wentThrough = true;
        newChar = (int)(unsigned char)mapArray[row][column];
    }
    if(wentThrough) column++;
    newChar = (int)(unsigned char)mapArray[row][column];
    while(column < w && ((ASCII_0 <= newChar && newChar <= ASCII_9) || (ASCII_A <= newChar && newChar <= ASCII_Z))){
        newString->AddChar((char)newChar);
        column++;
        newChar = (int)(unsigned char)mapArray[row][column];
    }
    //sslString.InsertNodeAtTail(newString, RowN, ColN);
    hashmap.PutIntoMain(newString, RowN, ColN, cityID);
    cityID++;
}
void MapParser::ParseWholeMap() {

    for(int i = 0; i < h; i++){
        int j = 0;
        while(j < w){
            mapPoint = (char)getchar();
            if((int)mapPoint < 33){
                continue;
            }
            if(mapPoint == '*'){
                sslChars.InsertNodeAtTail(nullptr, i,j,0);
            }
            mapArray[i][j] = mapPoint;
            j++;
        }
    }
    auto* sslCharsTemp = sslChars.getHead();
    while(sslCharsTemp){
        CitySearch(sslCharsTemp->row, sslCharsTemp->column);
        sslCharsTemp = sslCharsTemp->next;
    }
    bfs = new BFS(&hashmap, mapArray, w, h);
    bfs->SearchForRoute();
    for(int i = 0; i < h; i++){
        delete[] mapArray[i];
    }
    delete[] mapArray;
    auto* starting = new String;
    auto* finishing = new String;
    while((c = (char)getchar()) == '\n');
    ParseFlights();
    ParseCities();
    delete starting;
    delete finishing;
}

void MapParser::ParseFlights() {
    String numberOfFlights;
    while(c != '\n'){
        numberOfFlights.AddChar(c);
        c = (char)getchar();
    }
    int numberOfFlightsInt = numberOfFlights.StringToIntConversion();
    for(int i = 0; i < numberOfFlightsInt; i++){
        String startingCity;
        String finishingCity;
        int distanceFromTo = ParseCommands(&startingCity, &finishingCity);
       // sslString.SearchForNodesForFlights(startingCity, finishingCity, distanceFromTo);
        int cityID = hashmap.Get(finishingCity)->cityID;
        hashmap.Put(&startingCity, distanceFromTo, &finishingCity, cityID);
    }
}
void MapParser::ParseCities(){
    String numberOfCommands;
    while((c = (char)getchar()) != '\n'){
        numberOfCommands.AddChar(c);
    }
    int numbersOfCommandsInt = numberOfCommands.StringToIntConversion();
    for(int i = 0; i < numbersOfCommandsInt; i++){
        DoubleLinkedList TravelledCities;
        auto* startingCity = new String;
        auto* finishingCity = new String;
        int commandNr = ParseCommands(startingCity, finishingCity);
        auto* dijkstraParsing = new Dijkstra(&hashmap, &TravelledCities, startingCity, finishingCity);
        int distance = dijkstraParsing->ProcessGraph();
        std::cout << distance << " ";
        if(commandNr == 1){
        auto* nodeCheck = TravelledCities.getHead();
            while(nodeCheck){
                std::cout << nodeCheck->data->c_str() << " ";
                nodeCheck = nodeCheck->next;
            }
        }
        std::cout << std::endl;
        delete dijkstraParsing;
        delete startingCity;
        delete finishingCity;
    }
}
int MapParser::ParseCommands(String* startingCity, String* finishingCity){
    c = (char)getchar();
    while(c != ' '){
        startingCity->AddChar(c);
        c = (char)getchar();
    }
    c = (char)getchar();
    while(c != ' '){
        finishingCity->AddChar(c);
        c = (char)getchar();
    }
    c = (char)getchar();
    String distanceTemp;
    while(c != '\n'){
        distanceTemp.AddChar(c);
        c = (char)getchar();
    }
    return distanceTemp.StringToIntConversion();
}

MapParser::~MapParser() {

    delete bfs;
}