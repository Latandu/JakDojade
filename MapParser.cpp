//
// Created by Latandu on 25/04/2023.
//

#include "MapParser.h"
#include "String.h"
#include <iostream>
MapParser::MapParser() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> w >> h;
    mapArray = new char*[h];
    for(int i = 0; i < h; i++){
        mapArray[i] = new char[w];
    }
}
bool MapParser::CitySearch(int row, int column){
    int newRow, newCol;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
           newRow = row + i;
            newCol = column + j;
            if (i == 0 && j == 0) {
                continue;
            }
            if (newRow >= 0 && newRow < h && newCol >= 0 && newCol < w) {
                int newChar = (int)mapArray[newRow][newCol];
                if((ASCII_0 <= newChar && newChar <= ASCII_9) || (ASCII_A <= newChar && newChar <= ASCII_Z)){
                    ParseCity(newRow, newCol);
                    return true;
                }
            }
        }
    } return false;

}
void MapParser::ParseCity(int row, int column){
    auto *newString = new String;
    int newChar = (int)mapArray[row][column];
    while(column > 0 && ((ASCII_0 <= newChar && newChar <= ASCII_9) || (ASCII_A <= newChar && newChar <= ASCII_Z))){
        column--;
        newChar = (int)mapArray[row][column];
    }
    column++;
    newChar = (int)mapArray[row][column];
    while(column < w && ((ASCII_0 <= newChar && newChar <= ASCII_9) || (ASCII_A <= newChar && newChar <= ASCII_Z))){
        newString->AddChar((char)newChar);
        column++;
        newChar = (int)mapArray[row][column];
    }
    InsertNodeAtTail(newString);

}
char MapParser::AvoidWhiteSpaces(char checkC){
    if(checkC == '\n' || checkC == '\t' || checkC ==' ' || checkC == '\r'){
        checkC = (char)getchar();
        AvoidWhiteSpaces(checkC);
    }
    return checkC;
};
void MapParser::ParseWholeMap() {
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            mapPoint = (char)getchar();
            mapPoint = AvoidWhiteSpaces(mapPoint);
            mapArray[i][j] = mapPoint;
        }
    }
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(mapArray[i][j] == '*'){
                CitySearch(i, j);
            }
        }
    }
    auto *newString = new String;
    newString->AddChar('A');
    InsertNodeAtTail(newString);

}
MapParser::~MapParser() {
    for(int i = 0; i < h; i++){
        delete[] mapArray[i];
    }
    delete[] mapArray;
}