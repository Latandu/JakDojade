//
// Created by Latandu on 28/04/2023.
//

#ifndef JAKDOJADE_DIJKSTRA_H
#define JAKDOJADE_DIJKSTRA_H

#include "DoubleLinkedList.h"
#include "Hashmap.h"

class Dijkstra {
private:
    DoubleLinkedList* travelledNodes;
    Hashmap* hashmap;
    String* startingNode;
    String* finishingNode;
public:
    Dijkstra(Hashmap *hashmap1, DoubleLinkedList *travelledCities, String *startingNode, String *finishingNode);
    int ProcessGraph();
};


#endif //JAKDOJADE_DIJKSTRA_H
