//
// Created by Latandu on 01/05/2023.
//

#include "Hashmap.h"

Hashmap::Hashmap(){
    for(auto & i : table){
        i = new DoubleLinkedList;
    }
}

unsigned long Hashmap::HashFunc(const String &key) {
   //djb2 hashing algorithm
    char* t  = key.c_str();
    int c;
    unsigned long hash = 5381;
    c = (int)(unsigned char)*t++;
    while(c){
         hash = ((hash << 5) + hash) + c;
        c = (int)(unsigned char)*t++;
    }
    return hash % SIZE;
}

void Hashmap::Put(String *key, int distance, String *City, int cityID) {
    unsigned long hash = HashFunc(*key);
    table[hash]->GetNodeByName(*key)->adjacencyList->InsertNodeAtTailWithoutAL(City, distance, cityID);
}
void Hashmap::PutIntoMain(String* key, int row, int column, int cityID){
    unsigned long hash = HashFunc(*key);
    table[hash]->InsertNodeAtTail(key, row, column, cityID);
    counter = cityID;
}

DoubleLinkedList::SingleNode* Hashmap::Get(const String& key){
    unsigned long index = HashFunc(key);
    return table[index]->GetNodeByName(key);

}
DoubleLinkedList * Hashmap::GetByID(int x){
    return table[x];
}
void Hashmap::AddNeighbours(const DoubleLinkedList *bfs, DoubleLinkedList::SingleNode *checkingNode, int moveCount,
                        int bfsPointX, int bfsPointY) {
    bool finished = false;
    for(int i2 = 0; i2 < Hashmap::getSize(); i2++){
        DoubleLinkedList* bfs2 = GetByID(i2);
        if(bfs->getHead() == nullptr) continue;
        auto* currentNode = bfs2->getHead();
        while(currentNode){
            if(currentNode->row == bfsPointX && currentNode->column == bfsPointY){
                checkingNode->adjacencyList->InsertNodeAtTailWithoutAL(currentNode->data, moveCount + 1, currentNode->cityID);
                finished = true;
                break;
            }
            currentNode = currentNode->next;
        }
        if(finished) break;
    }
}
int Hashmap::getSize() {
    return SIZE;
}

int Hashmap::getCounter() const {
    return counter + 1;
}
Hashmap::~Hashmap(){
    for(auto & i : table){
        delete i;
    }
}