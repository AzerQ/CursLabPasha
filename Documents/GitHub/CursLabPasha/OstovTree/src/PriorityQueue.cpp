#include "include/PriorityQueue.h"

PriorityQueue::PriorityQueue(int capacity) {
    this->capacity = capacity;
    size = 0;
    heap.resize(capacity);
    position.resize(capacity);
}

bool PriorityQueue::isEmpty() {
    return size == 0;
}

void PriorityQueue::insert(int vertex, int key) {
    if (size == capacity) {
        return;
    }

    HeapNode newNode;
    newNode.vertex = vertex;
    newNode.key = key;
    heap[size] = newNode;
    position[vertex] = size;

    int current = size;
    int parentIndex = parent(current);
    while (current != 0 && heap[current].key < heap[parentIndex].key) {
        swapHeapNodes(current, parentIndex);
        current = parentIndex;
        parentIndex = parent(current);
    }

    ++size;
}

int PriorityQueue::extractMin() {
    if (isEmpty()) {
        return -1;
    }

    HeapNode minNode = heap[0];
    HeapNode lastNode = heap[size - 1];
    heap[0] = lastNode;
    position[minNode.vertex] = -1;
    position[lastNode.vertex] = 0;

    --size;
    minHeapify(0);

    return minNode.vertex;
}

void PriorityQueue::minHeapify(int index) {
    int smallest = index;
    int leftChildIndex = leftChild(index);
    int rightChildIndex = rightChild(index);

    if (leftChildIndex < size && heap[leftChildIndex].key < heap[smallest].key) {
        smallest = leftChildIndex;
    }

    if (rightChildIndex < size && heap[rightChildIndex].key < heap[smallest].key) {
        smallest = rightChildIndex;
    }

    if (smallest != index) {
        swapHeapNodes(index, smallest);
        minHeapify(smallest);
    }
}

void PriorityQueue::swapHeapNodes(int index1, int index2) {
    HeapNode temp = heap[index1];
    heap[index1] = heap[index2];
    heap[index2] = temp;

    position[heap[index1].vertex] = index1;
    position[heap[index2].vertex] = index2;
}

int PriorityQueue::parent(int index) {
    return (index - 1) / 2;
}

int PriorityQueue::leftChild(int index) {
    return 2 * index + 1;
}

int PriorityQueue::rightChild(int index) {
    return 2 * index + 2;
}
