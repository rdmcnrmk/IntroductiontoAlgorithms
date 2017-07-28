//
//  GraphWithLists.h
//  IntroductionToAlgorithms
//
//  Created by Erdem Can Irmak on 7/20/17.
//  Copyright © 2017 Erdem Can Irmak. All rights reserved.
//

#ifndef GraphWithLists_h
#define GraphWithLists_h

#include <vector>

struct AdjListNode {
    int value;
    int weight;
    AdjListNode *next;
};

struct AdjList {
    AdjListNode *head;
};

class GraphWithLists {
    
public:
    
    int vertexCount;
    AdjList *vertices;
    int *inDegree;
    
    GraphWithLists(int vertexCount);
    void AddEdge(int v1, int v2, int weight, bool directed);
    void PrintGraph();
};


GraphWithLists::GraphWithLists(int vertexCount) {
    this->vertexCount = vertexCount;
    this->vertices = new AdjList[vertexCount];
    this->inDegree = new int[vertexCount];
    
    for (int i = 0; i < vertexCount; i++) {
        vertices[i].head = nullptr;
        inDegree[i] = 0;
    }
}

void GraphWithLists::AddEdge(int v1, int v2, int weight, bool directed) {
    
    AdjListNode *node = new AdjListNode();
    node->value = v2;
    node->weight = weight;
    node->next = nullptr;
    inDegree[v2]++;
    
    AdjList *list = &vertices[v1];
    
    if(list->head == nullptr) {
        list->head = node;
    }
    else {
        AdjListNode *listNode = list->head;
        while (listNode->next != nullptr) {
            listNode = listNode->next;
        }
        listNode->next = node;
    }
    
    if(!directed) {
        AddEdge(v2, v1, weight, true);
    }
}

void GraphWithLists::PrintGraph() {
    
    for (int i = 0; i < vertexCount; i++) {
        AdjListNode *node = vertices[i].head;
        
        cout << i << ": ";
        
        while(node != nullptr) {
            cout << node->value << " ";
            node = node->next;
        }
        cout << endl;
    }
}



#endif /* GraphWithLists_h */
