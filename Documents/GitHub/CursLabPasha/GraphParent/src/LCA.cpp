#include "include/LCA.h"
#include <iostream>
LCA::LCA(const Graph& graph) : graph(graph) {
    int numVertices = graph.getNumVertices();
    parent.resize(numVertices);
    depth.resize(numVertices);

    dfs(0, -1, 0);
}

void LCA::dfs(int vertex, int par, int dep) {
    parent[vertex] = par;
    depth[vertex] = dep;

    const std::vector<int>& adjacentVertices = graph.getAdjacentVertices(vertex);
    for (int adjVertex : adjacentVertices) {
        if (adjVertex != par) {
            dfs(adjVertex, vertex, dep + 1);
        }
    }
}

void LCA::printAncestors(int vertex) const {
    while (vertex != -1) {
        std::cout << vertex << " ";
        vertex = parent[vertex];
    }
    std::cout << std::endl;
}

int LCA::findParent(int vertex, int levelDiff) const {
    while (levelDiff > 0) {
        vertex = parent[vertex];
        levelDiff--;
    }
    return vertex;
}

int LCA::findLCA(int u, int v) const {
    int uDepth = depth[u];
    int vDepth = depth[v];

    if (uDepth < vDepth) {
        v = findParent(v, vDepth - uDepth);
    } else if (vDepth < uDepth) {
        u = findParent(u, uDepth - vDepth);
    }

    while (u != v) {
        u = parent[u];
        v = parent[v];
    }

    return u;
}
