//
// Created by Latandu on 25/04/2023.
//

#include "SingleLinkedList.h"

void SingleLinkedList::InsertNodeAtTail(String *City) {
    auto* newNode = new struct SingleNode();
    newNode->data = City;
    newNode->next = nullptr;
    if(!head){
        newNode->next = nullptr;
        head = newNode;
        return;
    }
    tail = head;
    while(tail->next != nullptr){
        tail = tail->next;
    }
    tail->next = newNode;
}

SingleLinkedList::~SingleLinkedList() {
    while(head){
        auto* temp = head;
        head = head->next;
        delete temp->data;
        delete temp;
    }
}
