//
// Created by Latandu on 27/04/2023.
//

#ifndef JAKDOJADE_NEIGHBOURINGLIST_H
#define JAKDOJADE_NEIGHBOURINGLIST_H

#include "String.h"

class NeighbouringList {
public:
    struct SingleNode{
        String* data;
        SingleNode* next;
        int cityID = 0;
        int getCityId() const;
        int mover = 0;
    };
    SingleNode *getTail() const;
    SingleNode *getHead() const;
    struct SingleNode* tail = nullptr;
    struct SingleNode* head = nullptr;
    NeighbouringList() = default;
    void InsertNodeAtTailWithoutAL(String* data, int moveCount, int cityID);
    ~NeighbouringList();
};


#endif //JAKDOJADE_NEIGHBOURINGLIST_H
