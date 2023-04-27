//
// Created by Latandu on 25/04/2023.
//

#ifndef JAKDOJADE_MAPPARSER_H
#define JAKDOJADE_MAPPARSER_H
#include "Point.h"

#include "SingleLinkedList.h"
#include "BFS.h"

class MapParser {
private:
    int w,h;
    char c, mapPoint;
    char** mapArray;
    Point coordiantes;
    SingleLinkedList<Point> sslChars;
    const int ASCII_A = 65;
    const int ASCII_Z = 90;
    const int ASCII_0 = 48;
    const int ASCII_9 = 57;
    SingleLinkedList<String> sslString;
    BFS* bfs;
public:
    MapParser();
    ~MapParser();

    void ParseWholeMap();
    char AvoidWhiteSpaces(char checkC);

    bool CitySearch(int row, int column);


    void ParseCity(int row, int column, Point *point);
};


#endif //JAKDOJADE_MAPPARSER_H
