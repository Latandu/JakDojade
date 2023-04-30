cmake_minimum_required(VERSION 3.25)
project(JakDojade)

set(CMAKE_CXX_STANDARD 17)

add_executable(JakDojade main.cpp String.cpp String.h MapParser.cpp MapParser.h DoubleLinkedList.cpp DoubleLinkedList.h Queue.cpp Queue.h BFS.cpp BFS.h NeighbouringList.cpp NeighbouringList.h Dijkstra.cpp Dijkstra.h PriorityQueue.cpp PriorityQueue.h)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")