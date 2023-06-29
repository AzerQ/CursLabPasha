#include <iostream>
#include <vector>
#include "include/Graph.h"
#include "include/MinimumSpanningTree.h"
#include <cstdlib>

using namespace std;

void printMinimumSpanningTree(std::vector<Edge> mst)
{
    cout << "Остовное дерево:" << endl;
    int totalWeight = 0;
    for (const auto &edge : mst)
    {
        cout << edge.src << " -- " << edge.dest << " (" << edge.weight << ")" << endl;
        totalWeight += edge.weight;
    }
    cout << "Вес остовного дерева: " << totalWeight << endl;
}

void runTestCases(bool detailedOutput = false)
{
    vector<vector<int>> testCases = {
        {5, 7, 0, 1, 2, 0, 2, 3, 1, 2, 1, 1, 3, 4, 2, 2, 3, 2, 2, 4, 3, 3, 4, 5},
        {5, 6, 0, 1, 2, 0, 2, 3, 1, 2, 1, 1, 3, 4, 2, 2, 4, 3, 3, 4, 5},
        {4, 4, 0, 1, 1, 1, 2, 2, 2, 3, 3, 3},
        {6, 9, 0, 1, 1, 0, 2, 5, 1, 3, 3, 1, 4, 6, 2, 3, 4, 2, 4, 2, 3, 5, 1, 3, 5, 4, 4, 5, 2},
        {6, 9, 0, 1, 1, 0, 2, 5, 1, 3, 2, 1, 4, 6, 2, 3, 4, 2, 4, 2, 3, 5, 1, 3, 5, 4, 4, 5, 2}};

    for (const auto &testCase : testCases)
    {
        int numVertices = testCase[0];
        int numEdges = testCase[1];
        Graph graph(numVertices);

        cout << "Исходные данные:\n";
        cout << "Количество вершин: " << numVertices << endl;
        cout << "Количество ребер: " << numEdges << endl;

        for (int i = 0; i < numEdges; i++)
        {
            int u = testCase[2 + 3 * i];
            int v = testCase[2 + 3 * i + 1];
            int weight = testCase[2 + 3 * i + 2];
            graph.addEdge(u, v, weight);
        }

        MinimumSpanningTree mst(graph);

        if (detailedOutput)
        {
            cout << "Исходный граф:\n";
            graph.printGraph();
            cout << endl;
        }

        cout << "Наименьшее остовное дерево (Минимальное остовное дерево):\n";
        printMinimumSpanningTree(mst.getMinimumSpanningTree());
    }
}

int main()
{
    system( "chcp 65001" );
    cout << "Программа для нахождения минимального остовного дерева (Минимальное остовное дерево)" << endl;
    cout << "Выберите режим работы:\n";
    cout << "1. Ввести данные вручную\n";
    cout << "2. Выполнить тест с заготовленными данными\n";
    int choice;
    cin >> choice;

    if (choice == 1)
    {
        int numVertices, numEdges;
        cout << "Введите количество вершин и ребер: ";
        cin >> numVertices >> numEdges;

        Graph graph(numVertices);

        cout << "Введите ребра в формате (u v w), где u и v - вершины, w - вес ребра:\n";
        for (int i = 0; i < numEdges; i++)
        {
            int u, v, weight;
            cin >> u >> v >> weight;
            graph.addEdge(u, v, weight);
        }

        MinimumSpanningTree mst(graph);

        cout << "Выберите режим вывода:\n";
        cout << "1. Подробный вывод\n";
        cout << "2. Краткий вывод\n";
        int outputChoice;
        cin >> outputChoice;

        bool detailedOutput = (outputChoice == 1);
        printMinimumSpanningTree(mst.getMinimumSpanningTree());
    }
    else if (choice == 2)
    {
        runTestCases(true);
    }
    else
    {
        cout << "Некорректный выбор." << endl;
    }

    return 0;
}
