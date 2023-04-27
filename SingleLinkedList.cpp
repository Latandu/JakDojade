//
// Created by Latandu on 25/04/2023.
//

#include "SingleLinkedList.h"
#include "Point.h"
#include "NeighbouringList.h"
template <class T>
void SingleLinkedList<T>::InsertNodeAtTail(T *data, Point* pointForStr) {
    auto* newNode = new struct SingleNode();
    newNode->data = data;
    newNode->point = pointForStr;
    newNode->next = nullptr;
    newNode->adjacencyList = new NeighbouringList;
    headEngine(newNode);
}

template<class T>
void SingleLinkedList<T>::headEngine(SingleLinkedList<T>::SingleNode *newNode) {
    if(!head){
        newNode->next = nullptr;
        head = newNode;

        return;
    }
    tail = head;
    while(tail->next != nullptr){
        tail = tail->next;
    }
    tail->counter = tail->counter + 1;
    tail->next = newNode;
}

template <class T>
SingleLinkedList<T>::~SingleLinkedList() {
    while(head){
        auto* temp = head;
        head = head->next;
        delete temp->data;
        delete temp->point;
        delete temp->adjacencyList;
        delete temp;
    }
}

template<class T>
T* SingleLinkedList<T>::GetNameOfCity(int row, int column){
    auto* curr = head;
    while(curr){
        if(curr->point->getRow() == row && curr->point->getColumn() == column) return curr->data;
        curr = curr->next;
    }
    return {};
}

template class SingleLinkedList<String>;
template class SingleLinkedList<Point>;