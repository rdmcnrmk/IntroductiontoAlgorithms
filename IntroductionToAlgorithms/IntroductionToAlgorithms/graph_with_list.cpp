//
//  graph_with_list.cpp
//  IntroductionToAlgorithms
//
//  Created by Erdem Can Irmak on 5/26/17.
//  Copyright © 2017 Erdem Can Irmak. All rights reserved.
//

#include "graph_with_list.h"

GraphWithList::GraphWithList(int vertices_count, bool directed):
GraphBase(vertices_count, directed){
    
    degree = new int[vertices_count+1];
    edges = new EdgeNode*[vertices_count+1];
    
    for(int i = 0; i <= vertices_count; i++) this->degree[i] = 0;
    for(int i = 0; i <= vertices_count; i++) this->edges[i] = NULL;
}

GraphWithList::~GraphWithList() {
    free(degree);
    free(edges);
}

void GraphWithList::PrintGraph() {
     EdgeNode *p;
     
     for(int i = 0; i < number_of_vertices; i++) {
         cout << i << ": ";
         p = edges[i];
         while (p != NULL) {
             cout << p->value << " ";
             p = p->next;
         }
         cout << endl;
     }
}

void GraphWithList::AddEdge(int v, int w) {
    AddEdgeHelper(v, w, is_directed);
}

void GraphWithList::AddEdgeHelper(int v, int w, bool directed) {
    EdgeNode *p;
    p = new EdgeNode();
    p->weight = NULL;
    p->value = w;
    p->next = edges[v];
    
    edges[v] = p;
    degree[v]++;
    
    if(!directed) {
        AddEdgeHelper(w, v, true);
    } else {
        number_of_edges++;
    }
}

EdgeNode** GraphWithList::GetEdges() {
    return edges;
}
