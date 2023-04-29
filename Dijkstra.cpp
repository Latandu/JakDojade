//
// Created by Latandu on 28/04/2023.
//

#include "Dijkstra.h"
#include "PriorityQueue.h"
#include <climits>
#include <iostream>

Dijkstra::Dijkstra(DoubleLinkedList<String>* ddlString, DoubleLinkedList<String>* travelledCities, String* startingNode, String* finishingNode) {
    this->ddlString = ddlString;
    this->startingNode = startingNode;
    this->finishingNode = finishingNode;
    this->travelledNodes= travelledCities;
}
int Dijkstra::ProcessGraph(){
    int* visited = new int[ddlString->getTail()->cityID + 1];
    int* distance = new int[ddlString->getTail()->cityID + 1];
    for(int i = 0; i < ddlString->getTail()->cityID + 1; i++){
        distance[i] = INT_MAX;
        visited[i] = false;
    }
    PriorityQueue priorityQueue;
    auto* temp = ddlString->getHead();
    while(!temp->data->CompareStrings(*startingNode)){
        temp = temp->next;
        if(temp == nullptr) exit(1);
    }
    distance[temp->cityID] = 0;
    bool firstValue = true;
    priorityQueue.PriorityEnQueue(0, temp->cityID, temp->data);
    while(priorityQueue.CheckIfExists()){
        int cityIDPrevious = priorityQueue.GetFront().cityID;
        auto* cityNamePrevious = new String;
        cityNamePrevious->CopyString(priorityQueue.GetFront().data);
        if(!firstValue) travelledNodes->InsertNodeAtTailWithoutAL(cityNamePrevious, cityIDPrevious);
        firstValue = false;
        priorityQueue.PriorityDeQueue();
        if (visited[cityIDPrevious]) {
            continue;
        }
        auto* myNode = ddlString->getHead();
        myNode = ddlString->GetNodeByName(*cityNamePrevious);
        if(myNode == nullptr){
            continue;
        }
        bool newChildFound = false;
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
                priorityQueue.PriorityEnQueue(distance[cityID], cityID, cityName);
                newChildFound = true;
            }
            if (cityName->CompareStrings(*finishingNode)) {
                int distanceReturn;
                if(travelledNodes->getTail() != nullptr) distanceReturn = distance[cityID] - travelledNodes->getTail()->counter;
                else distanceReturn = distance[cityID];
                delete[] distance;
                delete[] visited;
                return distanceReturn;
            }
            adjacencyTemp = adjacencyTemp->next;
            if(adjacencyTemp == nullptr && !newChildFound){
                travelledNodes->DeleteNode(cityIDPrevious);
            }
        }
    }
    delete[] distance;
    delete[] visited;
    return INT_MAX;
}
