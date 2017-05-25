//
//  DepthFirstSearch.h
//  IntroductionToAlgorithms
//
//  Created by Erdem Can Irmak on 5/22/17.
//  Copyright © 2017 Erdem Can Irmak. All rights reserved.
//

#ifndef DepthFirstSearch_h
#define DepthFirstSearch_h

#include "GraphWithList.h"

using namespace std;

enum EdgeClassTypes { TREE, BACK, FORWARD, CROSS, DEFAULT };

class DepthFirstSearch {
public:
    DepthFirstSearch(GraphWithList *graph);
    void ApplyDFS(int start);
    
private:
    bool *processed;
    bool *discovered;
    int *parent;
    int *entrytime;
    int *exittime;
    int *reachableAncestor;
    int *treeOutDegree;
    GraphWithList *graph;
    bool finished;
    
    int time;
    
    void processVertexEarly(int v);
    void processEdge(int v, int w);
    void processVertexLate(int v);
    void initializeSearch();
    int edgeClassification(int v, int w);
};


DepthFirstSearch::DepthFirstSearch(GraphWithList *graph) {
    
    int maximumVertex = graph->VertexCount();
    
    processed = new bool[maximumVertex+1];
    discovered = new bool[maximumVertex+1];
    parent = new int[maximumVertex+1];
    entrytime = new int[maximumVertex+1];
    exittime = new int[maximumVertex+1];
    reachableAncestor = new int[maximumVertex+1];
    treeOutDegree = new int[maximumVertex+1];
    finished = false;
    
    this->graph = graph;
    
    initializeSearch();
}

void DepthFirstSearch::ApplyDFS(int start) {
    EdgeNode *p;
    int y;
    
    discovered[start] = true;
    time = time + 1;
    entrytime[start] = time;
    
    processVertexEarly(start);
    p=graph->GetEdges()[start];
    
    while (p != NULL) {
        y = p->value;
        if(discovered[y] == false) {
            parent[y] = start;
            processEdge(start, y);
            ApplyDFS(y);
        }
        else if(!processed[y] || graph->IsDirected()) {
            processEdge(start, y);
        }
        
        p = p->next;
    }
    
    processVertexLate(start);
    time = time + 1;
    exittime[start] = time;
}

void DepthFirstSearch::initializeSearch() {
    for(int i =0; i < graph->VertexCount(); i++) {
        processed[i] = discovered[i] = false;
        parent[i] = -1;
        entrytime[i] = 0;
        exittime[i] = 0;
    }
    
    time = 0;
}

void DepthFirstSearch::processVertexEarly(int v) {
    cout << "processed vertex " << v << endl;
    reachableAncestor[v] = v;
}

void DepthFirstSearch::processEdge(int v, int w) {
    cout << "process edge " << v << " " << w << endl;
    if(discovered[w] && parent[v] != w) {
        cout << "Cycle from " << w << " " << v  << endl;
        finished = true;
    }
    
    int edgeClass; /* edge class */
    edgeClass = edgeClassification(v, w);
    
    if(edgeClass == TREE) {
        treeOutDegree[v] = treeOutDegree[v] + 1;
    }
    if(edgeClass == BACK && parent[v] != w) {
        if(entrytime[w] < entrytime[reachableAncestor[v]]) {
            reachableAncestor[v] = w;
        }
    }
    
}

void DepthFirstSearch::processVertexLate(int v) {
    
}

int DepthFirstSearch::edgeClassification(int v, int w) {
    if(parent[w] == v) return TREE;
    if(discovered[w] && !processed[w]) return BACK;
    if(processed[w] && (entrytime[w] > entrytime[v])) return FORWARD;
    if(processed[w] && (entrytime[w] < entrytime[v])) return CROSS;
    
    return DEFAULT;
}


#endif /* DepthFirstSearch_h */
