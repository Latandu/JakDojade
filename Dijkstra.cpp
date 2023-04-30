//
// Created by Latandu on 28/04/2023.
//

#include "Dijkstra.h"
#include "PriorityQueue.h"
#include <climits>
#include <iostream>

Dijkstra::Dijkstra(DoubleLinkedList* ddlString, DoubleLinkedList* travelledCities, String* startingNode, String* finishingNode) {
    this->ddlString = ddlString;
    this->startingNode = startingNode;
    this->finishingNode = finishingNode;
    this->travelledNodes= travelledCities;
}
int Dijkstra::ProcessGraph(){
    int* visited = new int[ddlString->getTail()->cityID + 1];
    int* distance = new int[ddlString->getTail()->cityID + 1];
    int* previous = new int[ddlString->getTail()->cityID + 1];
    for(int i = 0; i < ddlString->getTail()->cityID + 1; i++){
        distance[i] = INT_MAX;
        visited[i] = false;
        previous[i] = -1;
    }
    int firstCityID;
    PriorityQueue priorityQueue;
    auto* temp = ddlString->getHead();
    while(!temp->data->CompareStrings(*startingNode)){
        temp = temp->next;
        if(temp == nullptr) exit(1);
    }
    firstCityID = temp->cityID;
    distance[temp->cityID] = 0;
    priorityQueue.PriorityEnQueue(0, temp->cityID, temp->data);
    while(priorityQueue.CheckIfExists()){
        int cityIDPrevious = priorityQueue.GetFront().cityID;
        auto* cityNamePrevious = new String;
        cityNamePrevious->CopyString(priorityQueue.GetFront().data);
        priorityQueue.PriorityDeQueue();
        if (visited[cityIDPrevious]) {
            continue;
        }

        auto* myNode = ddlString->getHead();
        myNode = ddlString->GetNodeByName(*cityNamePrevious);
        if(myNode == nullptr){
            continue;
        }
        auto *adjacencyTemp = myNode->adjacencyList->getHead();
        while (adjacencyTemp) {
            int weight = adjacencyTemp->mover;
            int cityID = adjacencyTemp->cityID;
            if (visited[cityID]){
                adjacencyTemp = adjacencyTemp->next;
                continue;
            }
            visited[cityIDPrevious] = true;
            String *cityName = adjacencyTemp->data;
            if (distance[cityID] > distance[cityIDPrevious] + weight){
                distance[cityID] = distance[cityIDPrevious] + weight;
                previous[cityID] = cityIDPrevious;
                priorityQueue.PriorityEnQueue(distance[cityID], cityID, cityName);
            }
            adjacencyTemp = adjacencyTemp->next;
        }
        if (cityNamePrevious->CompareStrings(*finishingNode)) {
            int distanceReturn;
            distanceReturn = distance[cityIDPrevious];
            int currentNode = cityIDPrevious;
            while (currentNode != -1) {
                if(currentNode == cityIDPrevious){
                    currentNode = previous[currentNode];
                    continue;
                }
                if(currentNode == firstCityID) break;
                auto* newString = new String;
                newString->CopyString(ddlString->GetNodeByID(currentNode)->data);
                travelledNodes->InsertNodeAtHeadWithoutAL(newString, currentNode);
                currentNode = previous[currentNode];
            }
            delete[] distance;
            delete[] visited;
            delete[] previous;
            return distanceReturn;
        }
    }
    delete[] distance;
    delete[] visited;
    delete[] previous;
    return INT_MAX;
}
