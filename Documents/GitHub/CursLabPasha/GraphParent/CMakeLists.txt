cmake_minimum_required(VERSION 3.25)
project(GraphParent)

set(CMAKE_CXX_STANDARD 17)

include_directories(src/include)

add_executable(GraphParent
        src/include/Graph.h
        src/include/LCA.h
        src/Graph.cpp
        src/LCA.cpp
        src/main.cpp)
