#ifndef HEAP_H
#define HEAP_H

#include <climits> //want to use INT_MAX to represent "infinity"

class MinHeap {
public:
    MinHeap(int capacity) {
        // initialize and assign arrays and attributes
        heapArray = new int[capacity];
        keyArray = new int[capacity];
        position = new int[capacity];
        size = 0;
        this->capacity = capacity;

        heapArray[0] = keyArray[0] = position[0] = 0;
        size++;

        for (int i = 1; i < capacity; i++) {
            heapArray[i] = position[i] = i;
            keyArray[i] = INT_MAX;
            size++;
        }
    }

    ~MinHeap() {
        delete heapArray;
        delete keyArray;
        delete position;
    }

    void insert(int vertex, int key);
    int extractMin();
    void decreaseKey(int vertex, int newKey);
    bool isInMinHeap(int vertex);
    bool isEmpty();

private:
    int* heapArray;        // Heap of vertex indices
    int* keyArray;         // Corresponding key values
    int* position;         // Maps vertex to its position in heap
    int capacity;          // maximum amount of nodes allowed in heap
    int size;

    void minHeapify(int idx);
};

#endif