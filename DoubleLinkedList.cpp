//
// Created by Latandu on 25/04/2023.
//

#include <cstdlib>
#include "DoubleLinkedList.h"
#include "NeighbouringList.h"
void DoubleLinkedList::InsertNodeAtTail(String *data, int row, int column, int cityID) {
    auto* newNode = new struct SingleNode();
    newNode->data = data;
    newNode->row = row;
    newNode->cityID = cityID;
    newNode->column = column;
    newNode->next = nullptr;
    newNode->adjacencyList = new NeighbouringList;
    newNode->prev = tail;
    if (!head) {
        head = newNode;
    } else {
        tail->next = newNode;
    }
    tail = newNode;
}

void DoubleLinkedList::InsertNodeAtTailWithoutAL(String *data, int row, int column){
    auto* newNode = new struct SingleNode();
    newNode->data = data;
    newNode->row = row;
    newNode->column = column;
    newNode->next = nullptr;
    newNode->adjacencyList = nullptr;
    newNode->prev = tail;
    if (!head) {
        head = newNode;
    } else {
        tail->next = newNode;
    }
    tail = newNode;
}
void DoubleLinkedList::InsertNodeAtHeadWithoutAL(String *data, int cityID){
    auto* newNode = new struct SingleNode();
    newNode->data = data;
    newNode->next = nullptr;
    newNode->adjacencyList = nullptr;
    newNode->cityID = cityID;
    newNode->next = head;
    head = newNode;
}
void DoubleLinkedList::InsertNodeAtTailWithDistance(int cityID, int distance, String* cityName){
    auto* newNode = new struct SingleNode();
    newNode->data = cityName;
    newNode->cityID = cityID;
    newNode->next = nullptr;
    newNode->adjacencyList = nullptr;
    newNode->moveCount = distance;
    if(!head){
        newNode->prev = nullptr;
        head = newNode;
        tail = newNode;
        return;
    }
    if(head->moveCount > distance){
        newNode->next = head;
        head->prev = newNode;
        head = newNode;

    }
    else {
        newNode->prev = tail;
        if (!head) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
    }
}
/*void DoubleLinkedList::headEngine(DoubleLinkedList::SingleNode *newNode) {
    if(!head){
        newNode->prev = nullptr;
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}*/

DoubleLinkedList::~DoubleLinkedList() {
    while(head){
        auto* temp = head;
        head = head->next;
        delete temp->data;
        delete temp->adjacencyList;
        delete temp;
    }
}

void DoubleLinkedList::SearchForNodesForFlights(const String& startingFlight, String finishingFlight, int newDistance){
    auto* curr = head;
    auto* neighbourNew = curr->adjacencyList;
    int cityID;
    bool checked = false;
    while(curr){
        if(curr->data->CompareStrings(startingFlight)){
           neighbourNew = curr->adjacencyList;
           if(checked) break;
           checked = true;
        }
        if(curr->data->CompareStrings(finishingFlight)){
            cityID = curr->cityID;
            if(checked) break;
            checked = true;
        }
        curr = curr->next;
    }
    neighbourNew->InsertNodeAtTailWithoutAL(&finishingFlight, newDistance , cityID);
}

typename DoubleLinkedList::SingleNode * DoubleLinkedList::GetNameOfCity(int row, int column){
    auto* curr = head;
    while(curr){
        if(curr->row == row && curr->column == column) return curr;
        curr = curr->next;
    }
    return nullptr;
}
typename DoubleLinkedList::SingleNode * DoubleLinkedList::GetNodeByName(const String& compareData){
    auto* curr = head;
    while(curr){
        if(curr->data->CompareStrings(compareData)) return curr;
        curr = curr->next;
    }
    return {};
}
typename DoubleLinkedList::SingleNode * DoubleLinkedList::GetNodeByID(int id){
    auto* curr = head;
    while(curr){
        if(curr->cityID == id) return curr;
        curr = curr->next;
    }
    return {};
}

