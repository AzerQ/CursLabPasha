#include "include/MinimumSpanningTree.h"
#include <climits> 

MinimumSpanningTree::MinimumSpanningTree(Graph& graph) : graph(graph), priorityQueue(graph.numVertices) {
    initialize();
}

std::vector<Edge> MinimumSpanningTree::getMinimumSpanningTree() {
    std::vector<Edge> minimumSpanningTree;

    for (int i = 0; i < graph.numVertices; ++i) {
        if (!inMST[i]) {
            primAlgorithm(i);
        }
    }

    for (int i = 1; i < graph.numVertices; ++i) {
        Edge edge;
        edge.src = parent[i];
        edge.dest = i;
        edge.weight = graph.adjacencyMatrix[i][parent[i]];
        minimumSpanningTree.push_back(edge);
    }

    return minimumSpanningTree;
}

void MinimumSpanningTree::initialize() {
    key.resize(graph.numVertices, INT_MAX);
    parent.resize(graph.numVertices, -1);
    inMST.resize(graph.numVertices, false);
}

void MinimumSpanningTree::primAlgorithm(int startVertex) {
    priorityQueue.insert(startVertex, 0);
    key[startVertex] = 0;

    while (!priorityQueue.isEmpty()) {
        int currentVertex = priorityQueue.extractMin();
        inMST[currentVertex] = true;

        for (int i = 0; i < graph.numVertices; ++i) {
            int weight = graph.adjacencyMatrix[currentVertex][i];

            if (weight != 0 && !inMST[i] && weight < key[i]) {
                priorityQueue.insert(i, weight);
                key[i] = weight;
                parent[i] = currentVertex;
            }
        }
    }
}
