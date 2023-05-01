//
// Created by Latandu on 27/04/2023.
//

#include "NeighbouringList.h"
#include "String.h"
void NeighbouringList::InsertNodeAtTailWithoutAL(String *data, int moveCount, int cityID){
    auto* newPtr = new String(*data);
    auto* newNode = new struct SingleNode();
    newNode->data = newPtr;
    newNode->mover = moveCount;
    newNode->next = nullptr;
    newNode->cityID = cityID;
    newNode->prev = tail;
    if (!head) {
        head = newNode;
    } else {
        tail->next = newNode;
    }
    tail = newNode;
}
NeighbouringList::~NeighbouringList() {
    while(head){
        auto* temp = head;
        head = head->next;
        delete temp->data;
        delete temp;
    }
}

NeighbouringList::SingleNode *NeighbouringList::getTail() const {
    return tail;
}

NeighbouringList::SingleNode *NeighbouringList::getHead() const {
    return head;
}

int NeighbouringList::SingleNode::getCityId() const {
    return cityID;
}
