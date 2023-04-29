//
// Created by Latandu on 28/04/2023.
//

#ifndef JAKDOJADE_DIJKSTRA_H
#define JAKDOJADE_DIJKSTRA_H

#include "DoubleLinkedList.h"
class Dijkstra {
private:
    struct PointWithID {
        String* data;
        DoubleLinkedList<String> visitedNodes;
        int cityID;
        int distance;
    };
    DoubleLinkedList<String>* travelledNodes;
    DoubleLinkedList<String>* ddlString;
    String* startingNode;
    String* finishingNode;
public:
    Dijkstra(DoubleLinkedList<String> *ddlString, DoubleLinkedList<String> *travelledCities, String *startingNode,
             String *finishingNode);

    int ProcessGraph();
};


#endif //JAKDOJADE_DIJKSTRA_H
