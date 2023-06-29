#include "include/Graph.h"
#include <iostream>
Graph::Graph(int numVertices)
{
    this->numVertices = numVertices;
    adjacencyMatrix.resize(numVertices, std::vector<int>(numVertices, 0));
}

void Graph::addEdge(int src, int dest, int weight)
{
    adjacencyMatrix[src][dest] = weight;
    adjacencyMatrix[dest][src] = weight;
}

std::vector<Edge> Graph::getEdges()
{
    std::vector<Edge> edges;
    for (int i = 0; i < numVertices; ++i)
    {
        for (int j = i + 1; j < numVertices; ++j)
        {
            if (adjacencyMatrix[i][j] != 0)
            {
                Edge edge;
                edge.src = i;
                edge.dest = j;
                edge.weight = adjacencyMatrix[i][j];
                edges.push_back(edge);
            }
        }
    }
    return edges;
}

void Graph::printGraph()
{
    std::cout << "Отображение графа:\n";

    for (int i = 0; i < numVertices; ++i)
    {
        std::cout << "Вершина " << i << ":\n";

        // Вывод связей
        for (int j = 0; j < numVertices; ++j)
        {
            if (adjacencyMatrix[i][j] != 0)
            {
                std::cout << "  ";
                std::cout << "│ "; // Вертикальная линия
                std::cout << "Вершина " << j << " (Вес: " << adjacencyMatrix[i][j] << ")\n";
            }
        }

        // Вывод горизонтальных линий
        if (i != numVertices - 1)
        {
            std::cout << "  ";
            for (int j = 0; j < numVertices; ++j)
            {
                if (adjacencyMatrix[i][j] != 0)
                {
                    std::cout << "├─"; // Горизонтальная линия
                }
                else
                {
                    std::cout << "──"; // Пустое место
                }
            }
            std::cout << "┤\n";
        }
    }
}