//
// Created by Latandu on 25/04/2023.
//

#ifndef JAKDOJADE_MAPPARSER_H
#define JAKDOJADE_MAPPARSER_H

#include "DoubleLinkedList.h"
#include "BFS.h"
#include "Dijkstra.h"
#include "Hashmap.h"
class MapParser {
private:
    int w,h;
    char c, mapPoint{};
    char** mapArray;
    DoubleLinkedList sslChars;
    Hashmap hashmap;
    const int ASCII_A = 65;
    const int ASCII_Z = 90;
    const int ASCII_0 = 48;
    const int ASCII_9 = 57;
    DoubleLinkedList sslString;
    BFS* bfs{};
public:
    MapParser();
    ~MapParser();
    void ParseWholeMap();
    bool CitySearch(int row, int column);
    int ParseCommands(String *startingCity, String *finishingCity);

    void ParseFlights();

    void ParseCities();

    void ParseCity(int row, int column, int starPointX, int starPointY);
};


#endif //JAKDOJADE_MAPPARSER_H
