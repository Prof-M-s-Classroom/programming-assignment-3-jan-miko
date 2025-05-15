#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
using namespace std;

#include "heap.h"

class Graph {
public:
    Graph(int vertices) {
        numVertices = vertices;
        adjMatrix = new int*[numVertices];
        for (int i = 0; i < numVertices; i++)
        {
            adjMatrix[i] = new int[numVertices];
            for (int j = 0; j < numVertices; j++) {
                if (i == j)
                    adjMatrix[i][j] = 0;
                else
                    adjMatrix[i][j] = INT_MAX;
            }
        }
    }

    ~Graph() {
        delete adjMatrix;
    }

    void addEdge(int u, int v, int weight){
        adjMatrix[u][v] = adjMatrix[v][u] = weight;
    }

    void primMST() {
        // Must print MST edges and total weight
        int* parents = new int[numVertices]; //keeps track of current parent of nonvisited vertices
        MinHeap nonvisited = MinHeap(numVertices);
        for (int i = 0; i < numVertices; i++) { //loops through each vertex
            int currVisit = nonvisited.extractMin();

            for (int j = 0; j < numVertices; j++) { //updates each vertex's edge if smaller, new parent
                if (nonvisited.decreaseKey(j, adjMatrix[currVisit][j]))
                    parents[j] = currVisit;
            }
        }
        int totalWeight = 0;
        for (int i=1; i < numVertices; i++) { //prints out each edge
            cout << "edge (" << parents[i] << " - " << i << ") weight: " << adjMatrix[i][parents[i]] << endl;
            totalWeight += adjMatrix[i][parents[i]];
        }
        cout << "Total Weight: " << totalWeight << endl;
    }


private:
    int** adjMatrix;
    int numVertices;
};

#endif