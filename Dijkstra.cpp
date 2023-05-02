//
// Created by Latandu on 28/04/2023.
//

#include "Dijkstra.h"
#include "PriorityQueue.h"
#include "Hashmap.h"
#include <climits>
#include <iostream>

Dijkstra::Dijkstra(Hashmap* hashmap1, DoubleLinkedList* travelledCities, String* startingNode, String* finishingNode) {
    this->hashmap = hashmap1;
    this->startingNode = startingNode;
    this->finishingNode = finishingNode;
    this->travelledNodes= travelledCities;
}
int Dijkstra::ProcessGraph(){
    struct StringID{
        String* data;
        int cityID;
    };
    bool* visited = new bool[hashmap->getCounter() + 1];
    int* distance = new int[hashmap->getCounter() + 1];
    auto* previous = new StringID[hashmap->getCounter() + 1];
    for(int i = 0; i < hashmap->getCounter() + 1; i++){
        distance[i] = INT_MAX;
        visited[i] = false;
        previous[i].data = nullptr;
        previous[i].cityID = -1;
    }
    int firstCityID;
    PriorityQueue priorityQueue;
    auto* temp = hashmap->Get(*startingNode);
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

        auto* myNode = hashmap->Get(*cityNamePrevious);
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
                previous[cityID].data = cityNamePrevious;
                previous[cityID].cityID = cityIDPrevious;
                priorityQueue.PriorityEnQueue(distance[cityID], cityID, cityName);
            }
            adjacencyTemp = adjacencyTemp->next;
        }
        if (cityNamePrevious->CompareStrings(*finishingNode)) {
            int distanceReturn;
            distanceReturn = distance[cityIDPrevious];
            String* currentString = new String;
            int currentNode = cityIDPrevious;
            while (currentNode != -1) {
                if(currentNode == cityIDPrevious){
                    delete currentString;
                    currentString = previous[currentNode].data;
                    currentNode = previous[currentNode].cityID;
                    continue;
                }
                if(currentNode == firstCityID) break;
                auto* newString = new String;
                newString->CopyString(currentString);
                travelledNodes->InsertNodeAtHeadWithoutAL(newString, currentNode);
                delete currentString;
                currentString = previous[currentNode].data;
                currentNode = previous[currentNode].cityID;
            }
            delete currentString;
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
