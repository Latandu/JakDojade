//
// Created by Latandu on 26/04/2023.
//

#include "BFS.h"
#include <iostream>
#define foundCity 2
void BFS::SearchForRoute() {
    int** visited = new int*[lengthRow];
    for(int i = 0; i < lengthRow; i++){
        visited[i] = new int[lengthCol];
        for(int j = 0; j < lengthCol; j++){
            visited[i][j] = {false};
        }

    }
    auto* checkingNode = singleLinkedList->getHead();
    while(checkingNode) {
        Queue queue;
        for(int i = 0; i < lengthRow; i++){
            for(int j = 0; j < lengthCol; j++) visited[i][j] = false;
        }
        queue.enQueue(checkingNode->point->getRow(), checkingNode->point->getColumn());
        visited[checkingNode->point->getRow()][checkingNode->point->getColumn()] = true;
        while (queue.CheckifExists()) {
            Point p = queue.GetFront();
            if (visited[p.getRow()][p.getColumn()] == foundCity)
                continue;
            queue.deQueue();
            for (auto &direction: directions) {
                int bfsPointX = p.getRow() + direction[0];
                int bfsPointY = p.getColumn() + direction[1];
                if (bfsPointX < 0 || bfsPointY < 0 || bfsPointX >= lengthRow
                    || bfsPointY >= lengthCol)
                    continue;
                if (visited[bfsPointX][bfsPointY]) continue;
                if (mainArray[bfsPointX][bfsPointY] != '*' && mainArray[bfsPointX][bfsPointY] != '#') continue;
                if (mainArray[bfsPointX][bfsPointY] == '*' && visited[bfsPointX][bfsPointY] == false) {
                    int bfsFinishedX = 0;
                    int bfsFinishedY = 0;
                    for (auto &direction2: directions) {
                        bfsFinishedX = bfsPointX + direction2[0];
                        bfsFinishedY = bfsPointY + direction2[1];
                        if (bfsFinishedX< 0 || bfsFinishedY < 0 || bfsFinishedX>= lengthRow || bfsFinishedY >= lengthCol)
                            continue;
                        visited[bfsFinishedX][bfsFinishedY] = foundCity;
                    }
                    NeighbouringList* neighbouringList = checkingNode->adjacencyList;
                    String* newString(singleLinkedList->GetNameOfCity(bfsPointX, bfsPointY));
                    neighbouringList->InsertNodeAtTailWithoutAL(newString , 0);
                    break;
                }

                queue.enQueue(bfsPointX, bfsPointY);
                visited[bfsPointX][bfsPointY] = true;
            }
        }
        checkingNode = checkingNode->next;
    }
    for(int i = 0; i < lengthRow; i++){
        delete[] visited[i];
    }
    delete[] visited;
}

BFS::BFS(SingleLinkedList<String>* ssl, char** mainArray, int lengthCol, int lengthRow) {
    this->singleLinkedList = ssl;
    this->lengthRow = lengthRow;
    this->lengthCol = lengthCol;
    this->mainArray = mainArray;
}

BFS::~BFS() = default;
