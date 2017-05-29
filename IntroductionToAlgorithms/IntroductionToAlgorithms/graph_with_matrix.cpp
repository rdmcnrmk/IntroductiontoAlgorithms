//
//  graph_with_matrix.cpp
//  IntroductionToAlgorithms
//
//  Created by Erdem Can Irmak on 5/27/17.
//  Copyright © 2017 Erdem Can Irmak. All rights reserved.
//

#include "graph_with_matrix.h"

GraphWithMatrix::GraphWithMatrix(int vertices_count, bool directed):
GraphBase(vertices_count, directed){
    
    degree = new int[vertices_count+1];
    edges = new int*[vertices_count+1];
    
    for(int i = 0; i <= vertices_count; i++) this->degree[i] = 0;
    for(int i = 0; i <= vertices_count; i++) this->edges[i] = new int[vertices_count+1];
    
    for(int i = 0; i <= vertices_count; i++)
        for(int j = 0; j <= vertices_count; j++)
            edges[i][j] = 0;
}

GraphWithMatrix::~GraphWithMatrix() {
    free(degree);
    free(edges);
}

void GraphWithMatrix::PrintGraph() {
    
    for(int i = 0; i < number_of_vertices; i++) {
        
        for(int j = 0; j < number_of_vertices; j++) {
            cout << edges[i][j] << " ";
        }
        cout << endl;
    }
}

void GraphWithMatrix::AddEdge(int v, int w) {
    AddEdgeHelper(v, w, is_directed);
}

void GraphWithMatrix::AddEdgeHelper(int v, int w, bool directed) {
    edges[v][w] = 1;
    
    if(!directed) {
        edges[w][v] = 1;
    }
}

int** GraphWithMatrix::GetEdges() {
    return edges;
}
