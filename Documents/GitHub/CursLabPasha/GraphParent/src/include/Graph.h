#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

class Graph {
public:
    explicit Graph(int numVertices);

    void addEdge(int u, int v);
    void printGraph() const;

    int getNumVertices() const;
    const std::vector<int>& getAdjacentVertices(int vertex) const;

private:
    int numVertices;
    std::vector<std::vector<int>> adjacencyList;
};

#endif
