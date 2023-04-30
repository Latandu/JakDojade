//
// Created by Latandu on 26/04/2023.
//

#ifndef JAKDOJADE_BFS_H
#define JAKDOJADE_BFS_H

#include "DoubleLinkedList.h"
#include "Queue.h"
class BFS {
private:
    DoubleLinkedList* singleLinkedList;
    char const * const * mainArray;
    int directions[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};
    int lengthRow = 0;
    struct PointR{
        int x, y;
    };
    int lengthCol = 0;
public:
    BFS(DoubleLinkedList *ssl, char const * const *mainArray, int lengthCol, int lengthRow);
    void SearchForRoute();
    ~BFS();
};


#endif //JAKDOJADE_BFS_H
