//
//  DFS.h
//  IntroductionToAlgorithms
//
//  Created by Erdem Can Irmak on 7/20/17.
//  Copyright © 2017 Erdem Can Irmak. All rights reserved.
//

#ifndef DFS_h
#define DFS_h

#include "GraphWithLists.h"

class DFS {
    static void DFSHelper(GraphWithLists *graph, int startVertex, bool *visited);
public:
    static void ApplyDFS(GraphWithLists *graph, int startVertex);
};


void DFS::ApplyDFS(GraphWithLists * graph, int startVertex) {
    bool* visited = new bool[graph->vertexCount];
    
    for (int i = 0 ; i < graph->vertexCount; i++) {
        visited[i] = false;
    }
    visited[startVertex] = true;
    DFSHelper(graph, startVertex, visited);
}

void DFS::DFSHelper(GraphWithLists *graph, int startVertex, bool *visited) {
    cout << startVertex << endl;
    
    
    AdjListNode *node = graph->vertices[startVertex].head;
    
    while(node != nullptr) {
        if(!visited[node->value]) {
            visited[node->value] = true;
            DFSHelper(graph, node->value, visited);
        }
        node = node->next;
    }
}

#endif /* DFS_h */
