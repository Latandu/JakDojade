//
// Created by Latandu on 25/04/2023.
//

#ifndef JAKDOJADE_SINGLELINKEDLIST_H
#define JAKDOJADE_SINGLELINKEDLIST_H

#include "String.h"
class SingleLinkedList {
private:
    struct SingleNode{
        String* data;
        SingleNode* next;
    };
    struct SingleNode* tail = nullptr;
    struct SingleNode* head = nullptr;
protected:
    void InsertNodeAtTail(String* City);
public:
    SingleLinkedList() = default;
    ~SingleLinkedList();
};

#endif //JAKDOJADE_SINGLELINKEDLIST_H
