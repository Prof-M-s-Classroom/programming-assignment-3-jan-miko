#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
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

    void primMST();  // Must print MST edges and total weight

private:
    int** adjMatrix;
    int numVertices;
};

#endif