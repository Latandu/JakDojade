//
// Created by Latandu on 26/04/2023.
//

#include "Queue.h"

Queue::Queue() {
   front = nullptr;
   tail = nullptr;

}
void Queue::enQueue(int row, int column) {
    newPoint = new Point;
    newPoint->setRow(row);
    newPoint->setColumn(column);
    InsertNodeAtTailWithoutAL(newPoint);
    if(front == nullptr) front = getHead();
    tail = getTail();
}

void Queue::deQueue(){
    SingleNode* temp = head;
    head = head->next;
    front = head;
    tail = getTail();
    if(front == nullptr) tail = nullptr;
    delete temp->data;
    delete temp;
}
Point Queue::GetFront(){
    return *front->data;
}
bool Queue::isEmpty(){
    if(front == nullptr) return true;
    return false;
}
bool Queue::CheckifExists(){
    if(front == nullptr) return false;
    else return true;
}
