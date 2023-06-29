#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <vector>

struct HeapNode {
    int vertex;
    int key;
};

class PriorityQueue {
public:
    PriorityQueue(int capacity);
    bool isEmpty();
    void insert(int vertex, int key);
    int extractMin();

private:
    std::vector<HeapNode> heap;
    std::vector<int> position;
    int capacity;
    int size;

    void minHeapify(int index);
    void swapHeapNodes(int index1, int index2);
    int parent(int index);
    int leftChild(int index);
    int rightChild(int index);
};

#endif
