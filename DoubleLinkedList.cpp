//
// Created by Latandu on 25/04/2023.
//

#include <cstdlib>
#include "DoubleLinkedList.h"
#include "Point.h"
#include "NeighbouringList.h"
template <class T>
void DoubleLinkedList<T>::InsertNodeAtTail(T *data, Point* pointForStr) {
    auto* newNode = new struct SingleNode();
    newNode->data = data;
    newNode->point = pointForStr;
    newNode->next = nullptr;
    newNode->adjacencyList = new NeighbouringList;
    headEngine(newNode);
}
template <class T>
void DoubleLinkedList<T>::InsertNodeAtTailWithoutAL(T *data, int cityID){
    auto* newNode = new struct SingleNode();
    newNode->data = data;
    newNode->cityID = cityID;
    newNode->next = nullptr;
    newNode->point = nullptr;
    newNode->adjacencyList = nullptr;
    if(!head){
        newNode->prev = nullptr;
        head = newNode;
        tail = newNode;
        return;
    }
    tail = head;
    while(tail->next != nullptr){
        tail = tail->next;
    }
    newNode->counter = tail->counter + 1;
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}
template <class T>
void DoubleLinkedList<T>::InsertNodeAtTailWithoutAL(T *data){
    auto* newNode = new struct SingleNode();
    newNode->data = data;
    newNode->next = nullptr;
    newNode->point = nullptr;
    newNode->adjacencyList = nullptr;
    headEngine(newNode);
}
template <class T>
void DoubleLinkedList<T>::DeleteNode(int cityID){
    auto* curr = head;
    while (curr) {
        if (curr->cityID == cityID) {
            if (curr == head) {
                head = curr->next;
            }
            if (curr == tail) {
                tail = curr->prev;
            }
            if (curr->prev) {
                curr->prev->next = curr->next;
            }
            if (curr->next) {
                curr->next->prev = curr->prev;
            }
            delete curr;
            break;
        }
        curr = curr->next;
    }
}
template <class T>
void DoubleLinkedList<T>::InsertNodeAtTailWithDistance(int cityID, int distance, T* cityName){
    auto* newNode = new struct SingleNode();
    newNode->data = cityName;
    newNode->cityID = cityID;
    newNode->next = nullptr;
    newNode->point = nullptr;
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
        tail = head;
        while(tail->next != nullptr){
            tail = tail->next;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}
template<class T>
void DoubleLinkedList<T>::headEngine(DoubleLinkedList<T>::SingleNode *newNode) {
    if(!head){
        newNode->prev = nullptr;
        head = newNode;
        tail = newNode;
        return;
    }
    tail = head;
    while(tail->next != nullptr){
        tail = tail->next;
    }
    newNode->cityID = tail->cityID + 1;
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

template <class T>
DoubleLinkedList<T>::~DoubleLinkedList() {
    while(head){
        auto* temp = head;
        head = head->next;
        delete temp->data;
        delete temp->point;
        delete temp->adjacencyList;
        delete temp;
    }
}

template<> void DoubleLinkedList<String>::SearchForNodesForFlights(const String& startingFlight, String finishingFlight, int newDistance){
    auto* curr = head;
    while(curr){
        if(curr->data->CompareStrings(startingFlight)){
            auto* neighbourCurr = curr->adjacencyList->getHead();
            while(neighbourCurr){
                if(neighbourCurr->data->CompareStrings(finishingFlight)){
                    neighbourCurr->mover = newDistance;
                    return;
                }
                neighbourCurr = neighbourCurr->next;
            }
            auto* neighbourNew = curr->adjacencyList->getTail();
            curr->adjacencyList->InsertNodeAtTailWithoutAL(&finishingFlight, newDistance , neighbourNew->cityID);
        }
        curr = curr->next;
    }
}
template<class T>
typename DoubleLinkedList<T>::SingleNode * DoubleLinkedList<T>::GetNameOfCity(int row, int column){
    auto* curr = head;
    while(curr){
        if(curr->point->getRow() == row && curr->point->getColumn() == column) return curr;
        curr = curr->next;
    }
    return {};
}


template<> typename DoubleLinkedList<String>::SingleNode * DoubleLinkedList<String>::GetNodeByName(const String& compareData){
    auto* curr = head;
    while(curr){
        if(curr->data->CompareStrings(compareData)) return curr;
        curr = curr->next;
    }
    return {};
}
template class DoubleLinkedList<String>;
template class DoubleLinkedList<Point>;