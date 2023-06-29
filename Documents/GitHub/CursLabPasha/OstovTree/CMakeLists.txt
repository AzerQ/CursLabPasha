cmake_minimum_required(VERSION 3.25)
project(OstovTree)

set(CMAKE_CXX_STANDARD 17)

include_directories(src/include)

add_executable(OstovTree
        src/include/Graph.h
        src/include/MinimumSpanningTree.h
        src/include/PriorityQueue.h
        src/Graph.cpp
        src/main.cpp
        src/MinimumSpanningTree.cpp
        src/PriorityQueue.cpp)
