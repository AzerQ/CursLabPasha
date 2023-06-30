#ifndef LCA_H
#define LCA_H

#include "Graph.h"

class LCA {
public:
    explicit LCA(const Graph& graph);

    void printAncestors(int vertex) const;
    int findLCA(int u, int v) const;

private:
    const Graph& graph;
    std::vector<int> parent;
    std::vector<int> depth;

    void dfs(int vertex, int parent, int depth);
    int findParent(int vertex, int levelDiff) const;
};

#endif
