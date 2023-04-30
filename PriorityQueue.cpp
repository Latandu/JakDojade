//
// Created by Latandu on 28/04/2023.
//

#include "PriorityQueue.h"

PriorityQueue::PriorityQueue() {
    front = nullptr;
    tail = nullptr;
}
void PriorityQueue::PriorityEnQueue(int distance,int cityID, String* name){
    auto* newName = new String;
    newName->CopyString(name);
    InsertNodeAtTailWithDistance(cityID, distance, newName);
    front = getHead();
}
void PriorityQueue::PriorityDeQueue(){
    SingleNode* temp = head;
    head = head->next;
    front = head;
    if(front == nullptr){
        delete tail;
        tail = nullptr;
    }
    delete temp->data;
    delete temp;

}
bool PriorityQueue::CheckIfExists(){
    if(front == nullptr) return false;
    else return true;
}

PriorityQueue::PointWithID PriorityQueue::GetFront(){
    return {front->data, front->cityID, front->moveCount};
}