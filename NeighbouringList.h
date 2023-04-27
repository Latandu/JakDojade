//
// Created by Latandu on 27/04/2023.
//

#ifndef JAKDOJADE_NEIGHBOURINGLIST_H
#define JAKDOJADE_NEIGHBOURINGLIST_H

#include "String.h"

class NeighbouringList {
protected:
    struct SingleNode{
        String* data;
        SingleNode* next;
        SingleNode* prev;
        int mover = 0;
    };
    struct SingleNode* tail = nullptr;
    struct SingleNode* head = nullptr;
    void headEngine(SingleNode *newNode);
public:
    NeighbouringList() = default;
    void InsertNodeAtTailWithoutAL(String* data, int moveCount);
    ~NeighbouringList();
};


#endif //JAKDOJADE_NEIGHBOURINGLIST_H
