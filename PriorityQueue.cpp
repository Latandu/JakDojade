#include "PriorityQueue.h"

PriorityQueue::PriorityQueue() = default;

int PriorityQueue::Parent(int i){
    return (i -1)/2;
}

int PriorityQueue::LeftChild(int i){
    return((2*i) + 1);
}

int PriorityQueue::RightChild(int i){
    return((2*i) + 2);
}

template <typename T>
void PriorityQueue::Swap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}

void PriorityQueue::ShiftUp(int sizeToShift){
   while(sizeToShift > 0){
       int parent = Parent(sizeToShift);
       if(CityData[parent].distance <= CityData[sizeToShift].distance) break;
       Swap(CityData[parent], CityData[sizeToShift]);
       sizeToShift = parent;
   }
}

void PriorityQueue::ShiftDown(int sizeToShift){
   while(true){
       int left = LeftChild(sizeToShift);
       int right = RightChild(sizeToShift);
       int maxChild = sizeToShift;
       if(left < size && CityData[left].distance < CityData[maxChild].distance) maxChild = left;
       if(right < size && CityData[right].distance < CityData[maxChild].distance) maxChild = right;
       if(maxChild == sizeToShift) break;
       Swap(CityData[sizeToShift], CityData[maxChild]);
       sizeToShift = maxChild;
   }
}

void PriorityQueue::PriorityEnQueue(int distance,int cityID, const String& name){
    if(size == capacity){
        capacity *= 2;
        PointWithID* newPointWithID = new PointWithID[capacity];
        for(int i = 0; i < size; i++){
            newPointWithID[i] = CityData[i];
        }
        delete[] CityData;
        CityData = newPointWithID;
    }
    CityData[size].data = name;
    CityData[size].cityID = cityID;
    CityData[size].distance = distance;
    size++;
    ShiftUp(size - 1);
}

void PriorityQueue::PriorityDeQueue(){
    if(size == 0) return;
    size--;
    CityData[0] = CityData[size];
    ShiftDown(0);
}

bool PriorityQueue::CheckIfExists(){
    return size > 0;
}

PriorityQueue::PointWithID PriorityQueue::GetFront(){
    return {CityData[0].data, CityData[0].cityID, CityData[0].distance};
}

PriorityQueue::~PriorityQueue(){
    delete[] CityData;
}