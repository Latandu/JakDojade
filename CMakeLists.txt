cmake_minimum_required(VERSION 3.25)
project(JakDojade)

set(CMAKE_CXX_STANDARD 17)

add_executable(JakDojade main.cpp String.cpp String.h MapParser.cpp MapParser.h DoubleLinkedList.cpp DoubleLinkedList.h Queue.cpp Queue.h Point.cpp Point.h BFS.cpp BFS.h NeighbouringList.cpp NeighbouringList.h)
