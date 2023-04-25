//
// Created by Latandu on 25/04/2023.
//

#ifndef JAKDOJADE_MAPPARSER_H
#define JAKDOJADE_MAPPARSER_H

#include "SingleLinkedList.h"
class MapParser : public SingleLinkedList {
private:
    int w,h;
    char c, mapPoint;
    char** mapArray;
    const int ASCII_A = 65;
    const int ASCII_Z = 90;
    const int ASCII_0 = 48;
    const int ASCII_9 = 57;
public:
    MapParser();
    ~MapParser();

    void ParseWholeMap();
    char AvoidWhiteSpaces(char checkC);

    bool CitySearch(int row, int column);

    void ParseCity(int row, int column);
};


#endif //JAKDOJADE_MAPPARSER_H
