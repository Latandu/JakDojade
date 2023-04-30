//
// Created by Latandu on 26/04/2023.
//

#include "Queue.h"

Queue::Queue() {
   front = nullptr;
}
void Queue::enQueue(int row, int column) {
    InsertNodeAtTailWithoutAL(nullptr, row, column);
    if(front == nullptr) front = getHead();
    tail = getTail();
}
void Queue::deQueue(){
    SingleNode* temp = head;
    head = head->next;
    front = head;
    delete temp->data;
    delete temp;
}
Queue::PointR Queue::GetFront(){
    return {front->row, front->column};
}

bool Queue::CheckifExists(){
    if(front == nullptr) return false;
    else return true;
}
