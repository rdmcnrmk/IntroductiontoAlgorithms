//
//  BreadthFirstSearch.h
//  IntroductionToAlgorithms
//
//  Created by Erdem Can Irmak on 5/23/17.
//  Copyright © 2017 Erdem Can Irmak. All rights reserved.
//

#ifndef BreadthFirstSearch_h
#define BreadthFirstSearch_h


#include "GraphWithList.h"
#include <queue>

using namespace std;

enum Color { WHITE, BLACK, UNCOLORED };


class BreadthFirstSearch {
public:
    BreadthFirstSearch(GraphWithList *graph, int maximumVertex);
    void ApplyBFS(int start);
    void findpath(int start, int end);
    void findConnectedComponents();
    void applyTwoColoringGrphs();
private:
    
    bool *processed;
    bool *discovered;
    int *parent;
    bool bipartite;
    
    Color *colors;
    GraphWithList *graph;
    
    void processVertexEarly(int v);
    void processEdge(int v, int w);
    void processVertexLate(int v);
    void initializeSearch();
};

BreadthFirstSearch::BreadthFirstSearch(GraphWithList *graph, int maximumVertex) {
    processed = new bool[maximumVertex];
    discovered = new bool[maximumVertex];
    parent = new int[maximumVertex];
    colors = new Color[maximumVertex];
    this->graph = graph;
    
    initializeSearch();
}

void BreadthFirstSearch::ApplyBFS(int start) {
    queue<int> q;   /* queue of vertices to visit */
    int v;          /* current vertex */
    int y;          /* successor vertex */
    EdgeNode *p;    /* temporary pointer */
    
    initializeSearch();
    
    q.push(start);
    discovered[start] = true;
    
    while (!q.empty()) {
        v = q.front();
        q.pop();
        processVertexEarly(v);
        processed[v] = true;
        p = graph->GetEdges()[v];
        
        while(p != NULL) {
            y = p->value;
            if(!processed[y] || graph->IsDirected()) {
                processEdge(v, y);
            }
            if(!discovered[y]) {
                q.push(y);
                discovered[y] = true;
                parent[y] = v;
            }
            p = p->next;
        }
        processVertexLate(v);
    }
}

void BreadthFirstSearch::processVertexEarly(int v) {
    cout << "processed vertex " << v << endl;
}

/*void BreadthFirstSearch::processEdge(int v, int w) {
    cout << "process edge " << v << " " << w << endl;
}*/

void BreadthFirstSearch::processVertexLate(int v) {
    
}

void BreadthFirstSearch::findpath(int start, int end) {
    if(start == end || end == -1) {
        cout << start;
    }
    else {
        findpath(start, parent[end]);
        cout << " " << end;
    }
}

void BreadthFirstSearch::findConnectedComponents() {
    int c = 0; /* component number */
    
    initializeSearch();
    
    for(int i =0; i < graph->VertexCount(); i++) {
        if(!discovered[i]) {
            c = c+1;
            cout << "Component " << c << ": ";
            ApplyBFS(i);
            cout << endl;
        }
    }
}

void BreadthFirstSearch::initializeSearch() {
    for(int i =0; i < graph->VertexCount(); i++) {
        processed[i] = discovered[i] = false;
        parent[i] = -1;
    }
}

void BreadthFirstSearch::applyTwoColoringGrphs() {
    
    for(int i =0; i < graph->VertexCount(); i++) {
        colors[i] = UNCOLORED;
    }
    
    initializeSearch();
    
    bipartite = true;
    
    for (int i = 0; i < graph->VertexCount(); i++) {
        if(!discovered[i]) {
            colors[i] = WHITE;
            ApplyBFS(i);
        }
    }
}

void BreadthFirstSearch::processEdge(int v, int w) {
    if(colors[v] == colors[w]) {
        bipartite = false;
        cout << "Warning: not bipartite due to: " << v << ": " << colors[v]<< " " << w << " :" << colors[w] << endl;
    }
    
    if(colors[v] == WHITE) {
        colors[w] = colors[v] = BLACK;
        return;
    }
    if(colors[v] == BLACK) {
        colors[w] = colors[v] = WHITE;
        return;
    }
}



#endif /* BreadthFirstSearch_h */
