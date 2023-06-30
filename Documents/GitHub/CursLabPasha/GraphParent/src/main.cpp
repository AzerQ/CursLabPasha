#include <iostream>
#include <vector>
#include "include/Graph.h"
#include "include/LCA.h"
#include <cstdlib>
// Функция для ввода данных пользователем
void userInputData(Graph &graph) {
    int numVertices, numEdges;
    std::cout << "Введите количество вершин: ";
    std::cin >> numVertices;
    std::cout << "Введите количество ребер: ";
    std::cin >> numEdges;

    graph = Graph(numVertices);

    std::cout << "Введите ребра (формат: вершина1 вершина2):" << std::endl;
    for (int i = 0; i < numEdges; ++i) {
        int src, dest;
        std::cin >> src >> dest;
        graph.addEdge(src, dest);
    }
}

int main() {
    // Тестовый набор данных 1
    system("chcp 65001");
    Graph graph1(6);
    graph1.addEdge(0, 1);
    graph1.addEdge(0, 2);
    graph1.addEdge(1, 3);
    graph1.addEdge(2, 4);
    graph1.addEdge(2, 5);

    std::cout << "Тестовый набор данных 1:" << std::endl;
    std::cout << "Граф:" << std::endl;
    graph1.printGraph();
    std::cout << std::endl;

    LCA lca1(graph1);
    std::cout << "Предки вершины 3: ";
    lca1.printAncestors(3);

    int u1 = 3, v1 = 5;
    int lcaVertex1 = lca1.findLCA(u1, v1);
    std::cout << "Наименьший общий предок для вершин " << u1 << " и " << v1 << ": " << lcaVertex1 << std::endl;
    std::cout << std::endl;

    // Тестовый набор данных 2
    Graph graph2(5);
    graph2.addEdge(0, 1);
    graph2.addEdge(1, 2);
    graph2.addEdge(2, 3);
    graph2.addEdge(3, 4);

    std::cout << "Тестовый набор данных 2:" << std::endl;
    std::cout << "Граф:" << std::endl;
    graph2.printGraph();
    std::cout << std::endl;

    LCA lca2(graph2);
    std::cout << "Предки вершины 4: ";
    lca2.printAncestors(4);

    int u2 = 4, v2 = 2;
    int lcaVertex2 = lca2.findLCA(u2, v2);
    std::cout << "Наименьший общий предок для вершин " << u2 << " и " << v2 << ": " << lcaVertex2 << std::endl;
    std::cout << std::endl;

    // Тест 3

    int numVertices3 = 8;
    Graph graph3(numVertices3);
    graph3.addEdge(0, 1);
    graph3.addEdge(0, 2);
    graph3.addEdge(1, 3);
    graph3.addEdge(1, 4);
    graph3.addEdge(2, 5);
    graph3.addEdge(2, 6);
    graph3.addEdge(6, 7);
    std::cout << "Тестовый набор данных 3:" << std::endl;
    std::cout << "Граф:" << std::endl;
    graph3.printGraph();
    LCA lca3(graph3);
    int u3 = 3;
    int v3 = 5;
    int lca3val = lca3.findLCA(u3, v3);
    std::cout << "Наименьший общий предок вершин " << u3 << " и " << v3 << " : " << lca3val << std::endl;

    std::cout << "Предки вершины " << u3 << " : ";
    lca3.printAncestors(u3);

    std::cout << "Предки вершины " << v3 << " : ";
    lca3.printAncestors(v3);

    return 0;
}
