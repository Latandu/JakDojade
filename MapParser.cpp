//
// Created by Latandu on 25/04/2023.
//

#include "MapParser.h"
#include "String.h"
#include "Point.h"
#include "BFS.h"
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
    auto *point = new Point;
    point->setRow(row);
    point->setColumn(column);
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
                    ParseCity(newRow, newCol, point);
                    return true;
                }
            }
        }
    } return false;

}
void MapParser::ParseCity(int row, int column, Point* point){
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
    sslString.InsertNodeAtTail(newString, point);

}
char MapParser::AvoidWhiteSpaces(char checkC){
    if((int)checkC < 33){
        checkC = (char)getchar();
        AvoidWhiteSpaces(checkC);
    }
    return checkC;
};
void MapParser::ParseWholeMap() {
    for(int i = 0; i < h; i++){
        int j = 0;
        while(j < w){
            mapPoint = (char)getchar();
            if((int)mapPoint < 33){
                continue;
            }
            if(mapPoint == '*'){
                auto* starPoint = new Point;
                starPoint->setRow(i);
                starPoint->setColumn(j);
                sslChars.InsertNodeAtTail(starPoint, nullptr);
            }
            mapPoint = AvoidWhiteSpaces(mapPoint);
            mapArray[i][j] = mapPoint;
            j++;
        }
    }
    auto* sslCharsTemp = sslChars.getHead();
    while(sslCharsTemp){
        CitySearch(sslCharsTemp->data->getRow(), sslCharsTemp->data->getColumn());
        sslCharsTemp = sslCharsTemp->next;
    }
    bfs = new BFS(&sslString, mapArray, w, h);
    bfs->SearchForRoute();
}
MapParser::~MapParser() {
    for(int i = 0; i < h; i++){
        delete[] mapArray[i];
    }
    delete[] mapArray;
    delete bfs;
}