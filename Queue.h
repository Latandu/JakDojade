//
// Created by Latandu on 26/04/2023.
//

#ifndef JAKDOJADE_QUEUE_H
#define JAKDOJADE_QUEUE_H

#include "Point.h"
#include "SingleLinkedList.h"

class Queue : public SingleLinkedList<Point> {
private:
   SingleNode* front = getHead();
   SingleNode* tail = getTail();
    Point* newPoint;
public:
    Queue();
    void deQueue();

    Point GetFront();

    bool CheckifExists();

    bool isEmpty();

    void enQueue(int row, int column);
};


#endif //JAKDOJADE_QUEUE_H
