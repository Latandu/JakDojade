//
// Created by Latandu on 25/04/2023.
//

#ifndef JAKDOJADE_DOUBLELINKEDLIST_H
#define JAKDOJADE_DOUBLELINKEDLIST_H

#include "String.h"
#include "Point.h"
#include "NeighbouringList.h"
template<class T> class DoubleLinkedList {
protected:
    struct SingleNode{
        T* data;
        Point* point;
        SingleNode* next;
        SingleNode* prev;
        int moveCount = 0;
        NeighbouringList* adjacencyList;
        int counter = 0;

    };
    struct SingleNode* tail = nullptr;
    struct SingleNode* head = nullptr;
public:
    SingleNode *getTail() const {
        return tail;
    }
    DoubleLinkedList() = default;
    ~DoubleLinkedList();
    SingleNode * getHead() const {
        return head;
    }
    void InsertNodeAtTail(T *data, Point* pointForStr);

    T * GetNameOfCity(int row, int column);

    void headEngine(SingleNode *newNode);

    void InsertNodeAtTailWithoutAL(T *data);
};


#endif //JAKDOJADE_DOUBLELINKEDLIST_H
