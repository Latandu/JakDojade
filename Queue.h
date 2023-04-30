//
// Created by Latandu on 26/04/2023.
//

#ifndef JAKDOJADE_QUEUE_H
#define JAKDOJADE_QUEUE_H

#include "DoubleLinkedList.h"

class Queue : public DoubleLinkedList {
private:
   SingleNode* front = getHead();
   SingleNode* tail = getTail();
   struct PointR{
       int x, y;
   };
public:
    Queue();
    void deQueue();

    PointR GetFront();

    bool CheckifExists();

    void enQueue(int row, int column);
};


#endif //JAKDOJADE_QUEUE_H
