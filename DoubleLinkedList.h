//
// Created by Latandu on 25/04/2023.
//

#ifndef JAKDOJADE_DOUBLELINKEDLIST_H
#define JAKDOJADE_DOUBLELINKEDLIST_H

#include "String.h"
#include "NeighbouringList.h"
class DoubleLinkedList {
protected:
    struct SingleNode{
        String* data;
        int row, column;
        SingleNode* next;
        SingleNode* prev;
        int moveCount = 0;
        NeighbouringList* adjacencyList;
        int cityID = 0;
        int counter = 1;

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

    SingleNode * GetNameOfCity(int row, int column);

    void headEngine(SingleNode *newNode);

    SingleNode *GetNodeByName(const String &compareData);

    void DeleteNode(int cityID);

    void SearchForNodesForFlights(const String &startingFlight, String finishingFlight, int newDistance);

    SingleNode *GetNodeByID(int id);


    void InsertNodeAtTail(String *data, int x, int y);

    void InsertNodeAtTailWithoutAL(String *data, int cityID);

    void InsertNodeAtTailWithoutAL(String *data);

    void InsertNodeAtHeadWithoutAL(String *data, int cityID);

    void InsertNodeAtTailWithDistance(int cityID, int distance, String *cityName);

    void InsertNodeAtTailWithoutAL(String *data, int row, int column);
};


#endif //JAKDOJADE_DOUBLELINKEDLIST_H
