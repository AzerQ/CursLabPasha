#include "include/Graph.h"
#include <iostream>

Graph::Graph(int numVertices) : numVertices(numVertices) {
    adjacencyList.resize(numVertices);
}

void Graph::addEdge(int u, int v) {
    adjacencyList[u].push_back(v);
    adjacencyList[v].push_back(u);
}

void Graph::printGraph() const {
    for (int i = 0; i < numVertices; i++) {
        std::cout << "Вершина " << i << ":\n";
        for (const auto& vertex : adjacencyList[i]) {
            std::cout << "  │ Вершина " << vertex << "\n";
        }
        std::cout << "  ──├─├─┤\n";
    }
}

int Graph::getNumVertices() const {
    return numVertices;
}

const std::vector<int>& Graph::getAdjacentVertices(int vertex) const {
    return adjacencyList[vertex];
}
