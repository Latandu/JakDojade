//
// Created by Latandu on 01/05/2023.
//

#ifndef JAKDOJADE_HASHMAP_H
#define JAKDOJADE_HASHMAP_H
#include "String.h"
#include "NeighbouringList.h"
#include "DoubleLinkedList.h"
class Hashmap {
private:
    static const int SIZE = 99999;
    int counter = 0;
public:
    int getCounter() const;
public:
    static int getSize();
private:
    DoubleLinkedList* table[SIZE];
public:
    Hashmap();
    static unsigned long HashFunc(const String& key);
    DoubleLinkedList::SingleNode *Get(const String &key);
    void PutIntoMain(String *key, int row, int column, int cityID);
    ~Hashmap();
    DoubleLinkedList * GetByID(int x);

    DoubleLinkedList::SingleNode * GetByVertex(int row, int column);

    void Put(String *key, int distance, String *City, int cityID);
};


#endif //JAKDOJADE_HASHMAP_H
