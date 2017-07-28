//
//  BFS.h
//  IntroductionToAlgorithms
//
//  Created by Erdem Can Irmak on 7/20/17.
//  Copyright © 2017 Erdem Can Irmak. All rights reserved.
//

#ifndef BFS_h
#define BFS_h

#include <list>
#include "GraphWithLists.h"

class BFS {
public:
    static void ApplyBFS(GraphWithLists *graph, int startVertex);
};

void BFS::ApplyBFS(GraphWithLists *graph, int startVertex) {
    
    bool isVisited[graph->vertexCount];
    
    for (int i = 0; i < graph->vertexCount; i++) {
        isVisited[i] = false;
    }
    
    list<int> queue;
    queue.push_back(startVertex);
    isVisited[startVertex] = true;
    
    while(!queue.empty()) {
        int currentVertex = queue.front();
        cout << currentVertex << endl;
        
        queue.pop_front();
        
        AdjListNode *node = graph->vertices[currentVertex].head;
        
        while(node != nullptr) {
            if(!isVisited[node->value]) {
                queue.push_back(node->value);
                isVisited[node->value] = true;
            }
            node = node->next;
        }
    }
}

#endif /* BFS_h */
