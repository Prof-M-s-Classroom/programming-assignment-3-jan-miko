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
        delete[] heapArray;
        delete[] keyArray;
        delete[] position;
    }

    void insert(int vertex, int key) {
        // will not be using this method because the assumption is that we will only use the heap for the MST
        //all vertices are automatically inserted in the constructor and will be updated using the decrease key method
    }

    int extractMin() {
        if (size <= 0)
            return -1; // the heap is empty

        if (size == 1) {
            size --;
            return heapArray[0];
        }
        // store then delete minimum value
        int temp = heapArray[0];
        heapArray[0] = heapArray[size - 1];
        position[heapArray[size - 1]] = 0;
        size--;

        // heapify after removal
        minHeapify(0);

        return temp;
    }
    bool decreaseKey(int vertex, int newKey) {
        if (isInMinHeap(vertex) && (newKey < keyArray[vertex])) {
            keyArray[vertex] = newKey;
            minHeapify(0); //maintain minHeap properties
            return true;
        }
        else
            return false;
    }

    bool isInMinHeap(int vertex) {
        return (heapArray[position[vertex]] == vertex) && !isEmpty();
    }
    bool isEmpty() {
        return size == 0;
    }

private:
    int* heapArray;        // Heap of vertex indices
    int* keyArray;         // Corresponding key values
    int* position;         // Maps vertex to its position in heap
    int capacity;          // maximum amount of nodes allowed in heap
    int size;

    void minHeapify(int idx) { //recursively maintains minheap property
        //establish current index as the "minimum"
        int minimum = idx;

        //determine index of left child
        int left = 2 * idx + 1;

        //determine index of right child
        int right = 2 * idx + 2;

        //if the key of the left child is smaller than the parent/root node
        if (left < size && keyArray[heapArray[left]] < keyArray[heapArray[minimum]])
            minimum = left;

        //if the key of the right child is smaller than the other two
        if (right < size && keyArray[heapArray[right]] < keyArray[heapArray[minimum]])
            minimum = right;

        //if the parent node was not the root
        if (minimum != idx) {

            //swaps vertex positions
            int temp = heapArray[idx];
            heapArray[idx] = heapArray[minimum];
            heapArray[minimum] = temp;

            //updates position matrix
            position[heapArray[idx]] = idx;
            position[heapArray[minimum]] = minimum;

            minHeapify(minimum);
        }
    }
};

#endif