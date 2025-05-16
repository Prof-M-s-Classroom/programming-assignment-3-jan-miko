[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/K_t6ffJX)
# Prim's Algorithm with Min Heap and Adjacency Matrix

## Author
Jan Miko Bautista

## Description
The program creates a graph of n-amount of vertices with weighted edges.
It then uses Prim's algorithm to create a minimum spanning tree using the edges with lowest weights.

## Files
- graph.h / graph.cpp
- heap.h / heap.cpp
- main.cpp (unchanged)
- README.md

## How to Compile and Run
This project was developed and tested in CLion.  
Run directly from the IDE.

## Time Complexity Analysis

| Operation            | Time Complexity                                                                             |
|----------------------|---------------------------------------------------------------------------------------------|
| Insert in MinHeap    | N/A - constructor runs in O(n) time                                                         |
| Extract Min          | O(logn) - because it calls minHeapify which runs in logn time (would otherwise be constant) |
| Decrease Key         | O(logn) - because it also calls minHeapify which runs in logn time                          |
| Prim’s MST Overall   | O(nlogn) - calls minHeapify for every vertex                                                |

_Explain why your MST implementation has the above runtime._

## Test Case Description

Input:  Graph g(5);
g.addEdge(0, 1, 2);
g.addEdge(0, 3, 6);
g.addEdge(1, 2, 3);
g.addEdge(1, 3, 8);
g.addEdge(1, 4, 5);
g.addEdge(2, 4, 7);
g.addEdge(3, 4, 9);

    g.primMST();

Output: 
C:\Users\bauti\CLionProjects\programming-assignment-3-jan-miko\cmake-build-debug\PA3.exe
edge (0 - 1) weight: 2
edge (1 - 2) weight: 3
edge (0 - 3) weight: 6
edge (1 - 4) weight: 5
Total Weight: 16

Process finished with exit code 0
