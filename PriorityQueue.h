//
// Created by Latandu on 28/04/2023.
//

#ifndef JAKDOJADE_PRIORITYQUEUE_H
#define JAKDOJADE_PRIORITYQUEUE_H
#include "String.h"
class PriorityQueue {
private:
    struct PointWithID {
        String data;
        int cityID = 0;
        int distance =0;
    };
    int capacity = 1000;
    int size = 0;
    PointWithID* CityData = new PointWithID[capacity];
public:
    PriorityQueue();
    void PriorityDeQueue();
    ~PriorityQueue();
    bool CheckIfExists();

    PointWithID GetFront();

    void PriorityEnQueue(int distance, int cityID, const String& name);

    void ShiftUp(int sizeToShift);

    int Parent(int i);
    template <typename T>
    void Swap(T &a, T &b);

    int LeftChild(int i);

    int RightChild(int i);

    void ShiftDown(int sizeToShift);
};


#endif //JAKDOJADE_PRIORITYQUEUE_H
