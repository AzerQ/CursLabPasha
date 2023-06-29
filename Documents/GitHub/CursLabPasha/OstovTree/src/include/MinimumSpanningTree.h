#ifndef MINIMUMSPANNINGTREE_H
#define MINIMUMSPANNINGTREE_H

#include "Graph.h"
#include "PriorityQueue.h"

class MinimumSpanningTree {
public:
    MinimumSpanningTree(Graph& graph);
    std::vector<Edge> getMinimumSpanningTree();

private:
    Graph& graph;
    PriorityQueue priorityQueue;
    std::vector<int> key;
    std::vector<int> parent;
    std::vector<bool> inMST;

    void initialize();
    void primAlgorithm(int startVertex);
};

#endif
