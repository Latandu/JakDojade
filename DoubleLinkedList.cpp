//
// Created by Latandu on 25/04/2023.
//

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
void DoubleLinkedList<T>::InsertNodeAtTailWithoutAL(T *data){
    auto* newNode = new struct SingleNode();
    newNode->data = data;
    newNode->next = nullptr;
    newNode->point = nullptr;
    newNode->adjacencyList = nullptr;
    headEngine(newNode);
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

template<class T>
T* DoubleLinkedList<T>::GetNameOfCity(int row, int column){
    auto* curr = head;
    while(curr){
        if(curr->point->getRow() == row && curr->point->getColumn() == column) return curr->data;
        curr = curr->next;
    }
    return {};
}

template class DoubleLinkedList<String>;
template class DoubleLinkedList<Point>;