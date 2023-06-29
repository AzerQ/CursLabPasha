#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

struct Edge {
    int src;
    int dest;
    int weight;
};

class Graph {
public:
    Graph(int numVertices);
    void addEdge(int src, int dest, int weight);
    std::vector<Edge> getEdges();
    int numVertices;
    std::vector<std::vector<int>> adjacencyMatrix;
    void printGraph();
};

#endif
