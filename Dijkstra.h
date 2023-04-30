//
// Created by Latandu on 28/04/2023.
//

#ifndef JAKDOJADE_DIJKSTRA_H
#define JAKDOJADE_DIJKSTRA_H

#include "DoubleLinkedList.h"
class Dijkstra {
private:
    DoubleLinkedList* travelledNodes;
    DoubleLinkedList* ddlString;
    String* startingNode;
    String* finishingNode;
public:
    Dijkstra(DoubleLinkedList *ddlString, DoubleLinkedList *travelledCities, String *startingNode,
             String *finishingNode);

    int ProcessGraph();
};


#endif //JAKDOJADE_DIJKSTRA_H
