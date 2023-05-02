//
// Created by Latandu on 26/04/2023.
//

#include "BFS.h"
#include <iostream>
void BFS::SearchForRoute() {
    bool** visited = new bool*[lengthRow];
    for(int i = 0; i < lengthRow; i++){
        visited[i] = new bool[lengthCol];
        for(int j = 0; j < lengthCol; j++) visited[i][j] = false;
    }
    struct PointR p{};
    for(int iterator = 0; iterator < Hashmap::getSize(); iterator++){
        DoubleLinkedList* bfs = hashmap->GetByID(iterator);
        if(bfs->getHead() == nullptr)
            continue;
        auto* checkingNode = bfs->getHead();
        while(checkingNode) {
            int moveCount = 0;
            int nodesLeft = 1;
            int nodesToCheck = 0;
            Queue queue;
            Queue visitedQueue;
            queue.enQueue(checkingNode->row, checkingNode->column);
            NeighbouringList* neighbouringList = checkingNode->adjacencyList;
            neighbouringList->InsertNodeAtTailWithoutAL(checkingNode->data, 0, checkingNode->cityID);
            while (queue.CheckifExists()) {
                p.x = queue.GetFront().x;
                p.y = queue.GetFront().y;
                visitedQueue.enQueue(p.x, p.y);
                visited[p.x][p.y] = true;
                queue.deQueue();
                for (auto &direction: directions) {
                    int bfsPointX = p.x + direction[0];
                    int bfsPointY = p.y + direction[1];
                    if (bfsPointX < 0 || bfsPointY < 0 || bfsPointX >= lengthRow || bfsPointY >= lengthCol)
                        continue;
                    if (visited[bfsPointX][bfsPointY])
                        continue;
                    if (mainArray[bfsPointX][bfsPointY] != '*' && mainArray[bfsPointX][bfsPointY] != '#')
                        continue;
                    if (mainArray[bfsPointX][bfsPointY] == '*' && !visited[bfsPointX][bfsPointY]) {
                        visitedQueue.enQueue(bfsPointX, bfsPointY);
                        visited[bfsPointX][bfsPointY] = true;
                        int bfsFinishedX;
                        int bfsFinishedY;
                        for (auto &direction2: directions) {
                            bfsFinishedX = bfsPointX + direction2[0];
                            bfsFinishedY = bfsPointY + direction2[1];
                            if (bfsFinishedX< 0 || bfsFinishedY < 0 || bfsFinishedX>= lengthRow || bfsFinishedY >= lengthCol)
                                continue;
                            visitedQueue.enQueue(bfsFinishedX, bfsFinishedY);
                            visited[bfsFinishedX][bfsFinishedY] = true;
                        }
                        hashmap->AddNeighbours(bfs, checkingNode, moveCount, bfsPointX, bfsPointY);
                        continue;
                    }
                        queue.enQueue(bfsPointX, bfsPointY);
                        visitedQueue.enQueue(bfsPointX, bfsPointY);
                        visited[bfsPointX][bfsPointY] = true;
                        nodesToCheck++;
                }
                nodesLeft--;
                if(nodesLeft == 0){
                    nodesLeft = nodesToCheck;
                    nodesToCheck = 0;
                    moveCount++;
                }
            }
            checkingNode = checkingNode->next;
            while(visitedQueue.CheckifExists()){
                visited[visitedQueue.GetFront().x][visitedQueue.GetFront().y] = false;
                visitedQueue.deQueue();
            }
        }
    }
    for(int i = 0; i < lengthRow; i++){
        delete[] visited[i];
    }
    delete[] visited;
}

BFS::BFS(Hashmap* hashmap1,  char const * const * mainArray, int lengthCol, int lengthRow) {
    this->hashmap = hashmap1;
    this->lengthRow = lengthRow;
    this->lengthCol = lengthCol;
    this->mainArray = mainArray;
}

BFS::~BFS() = default;
