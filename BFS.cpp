//
// Created by Latandu on 26/04/2023.
//

#include "BFS.h"
#include <iostream>
void BFS::SearchForRoute() {
    int** visited = new int*[lengthRow];
    int** distance = new int*[lengthRow];
    for(int i = 0; i < lengthRow; i++){
        visited[i] = new int[lengthCol];
        distance[i] = new int[lengthCol];
        for(int j = 0; j < lengthCol; j++){
            visited[i][j] = false;
            distance[i][j] = 0;
        }

    }
    struct PointR p{};
    auto* checkingNode = singleLinkedList->getHead();
    while(checkingNode) {
        for(int i = 0; i < lengthRow; i++){
            for(int j = 0; j < lengthCol; j++){
                visited[i][j] = 0;
                distance[i][j] = 0;
            }
        }
        Queue queue;
        for(int i = 0; i < lengthRow; i++){
            for(int j = 0; j < lengthCol; j++) visited[i][j] = false;
        }
        queue.enQueue(checkingNode->row, checkingNode->column);
        NeighbouringList* neighbouringList = checkingNode->adjacencyList;
        auto* cityNameAndID = singleLinkedList->GetNameOfCity(checkingNode->row, checkingNode->column);
        neighbouringList->InsertNodeAtTailWithoutAL(cityNameAndID->data , 0, cityNameAndID->cityID);
        while (queue.CheckifExists()) {
            p.x = queue.GetFront().x;
            p.y = queue.GetFront().y;
            visited[p.x][p.y] = true;
            queue.deQueue();
            for (auto &direction: directions) {
                int bfsPointX = p.x + direction[0];
                int bfsPointY = p.y + direction[1];
                if (bfsPointX < 0 || bfsPointY < 0 || bfsPointX >= lengthRow
                    || bfsPointY >= lengthCol)
                    continue;
                if (visited[bfsPointX][bfsPointY]) continue;
                if (mainArray[bfsPointX][bfsPointY] != '*' && mainArray[bfsPointX][bfsPointY] != '#') continue;
                distance[bfsPointX][bfsPointY] = distance[p.x][p.y] + 1;
                if (mainArray[bfsPointX][bfsPointY] == '*' && visited[bfsPointX][bfsPointY] == false) {
                    visited[bfsPointX][bfsPointY] = true;
                    int bfsFinishedX;
                    int bfsFinishedY;
                    for (auto &direction2: directions) {
                        bfsFinishedX = bfsPointX + direction2[0];
                        bfsFinishedY = bfsPointY + direction2[1];
                        if (bfsFinishedX< 0 || bfsFinishedY < 0 || bfsFinishedX>= lengthRow || bfsFinishedY >= lengthCol)
                            continue;
                        visited[bfsFinishedX][bfsFinishedY] = true;
                    }
                    cityNameAndID = singleLinkedList->GetNameOfCity(bfsPointX, bfsPointY);
                    neighbouringList->InsertNodeAtTailWithoutAL(cityNameAndID->data , distance[bfsPointX][bfsPointY], cityNameAndID->cityID);
                    continue;
                }
                    queue.enQueue(bfsPointX, bfsPointY);
                    visited[bfsPointX][bfsPointY] = true;
            }
        }
        checkingNode = checkingNode->next;
    }
    for(int i = 0; i < lengthRow; i++){
        delete[] visited[i];
        delete[] distance[i];
    }
    delete[] visited;
    delete[] distance;
}

BFS::BFS(DoubleLinkedList* ssl,  char const * const * mainArray, int lengthCol, int lengthRow) {
    this->singleLinkedList = ssl;
    this->lengthRow = lengthRow;
    this->lengthCol = lengthCol;
    this->mainArray = mainArray;
}

BFS::~BFS() = default;
