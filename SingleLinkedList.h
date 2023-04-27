//
// Created by Latandu on 25/04/2023.
//

#ifndef JAKDOJADE_SINGLELINKEDLIST_H
#define JAKDOJADE_SINGLELINKEDLIST_H

#include "String.h"
#include "Point.h"
#include "NeighbouringList.h"
template<class T> class SingleLinkedList {
protected:
    struct SingleNode{
        T* data;
        Point* point;
        SingleNode* next;
        int mover = 0;
        NeighbouringList* adjacencyList;
        int counter = 0;

    };
    struct SingleNode* tail = nullptr;
    struct SingleNode* head = nullptr;
public:
    SingleNode *getTail() const {
        return tail;
    }
    SingleLinkedList() = default;
    ~SingleLinkedList();
    SingleNode * getHead() const {
        return head;
    }
    void InsertNodeAtTail(T *data, Point* pointForStr);

    T * GetNameOfCity(int row, int column);

    void headEngine(SingleNode *newNode);
    void InsertNodeAtTailWithoutAL(T *data, int moveCount);

    void InsertNodeAtTailWithoutAL(T *data);
};


#endif //JAKDOJADE_SINGLELINKEDLIST_H
