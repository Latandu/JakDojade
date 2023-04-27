//
// Created by Latandu on 27/04/2023.
//

#include "NeighbouringList.h"

void NeighbouringList::InsertNodeAtTailWithoutAL(String *data, int moveCount){
    auto* newNode = new struct SingleNode();
    newNode->data = data;
    newNode->next = nullptr;
    headEngine(newNode);
}
void NeighbouringList::headEngine(NeighbouringList::SingleNode *newNode) {
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
NeighbouringList::~NeighbouringList() {
    while(head){
        auto* temp = head;
        head = head->next;
        if(temp->data != nullptr) delete temp->data;
        delete temp;
    }
}
