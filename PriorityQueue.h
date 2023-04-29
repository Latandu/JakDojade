//
// Created by Latandu on 28/04/2023.
//

#ifndef JAKDOJADE_PRIORITYQUEUE_H
#define JAKDOJADE_PRIORITYQUEUE_H

#include "DoubleLinkedList.h"
class PriorityQueue : DoubleLinkedList<String>{
private:
    SingleNode* front = getHead();
    struct PointWithID {
        String* data;
        int cityID;
        int distance;
    };
    SingleNode* tail = getTail();
    Point* newPoint;
public:
    PriorityQueue();

    void PriorityDeQueue();

    bool CheckIfExists();

    PointWithID GetFront();

    void PriorityEnQueue(int distance, int cityID, String *name);
};


#endif //JAKDOJADE_PRIORITYQUEUE_H
