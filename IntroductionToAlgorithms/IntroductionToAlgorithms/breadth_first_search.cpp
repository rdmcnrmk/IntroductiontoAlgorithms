//
//  breadth_first_search.cpp
//  IntroductionToAlgorithms
//
//  Created by Erdem Can Irmak on 5/27/17.
//  Copyright © 2017 Erdem Can Irmak. All rights reserved.
//

#include <stdio.h>
#include "breadth_first_search.h"

BreadthFirstSearch::BreadthFirstSearch(GraphWithList *graph) {
    int maximum_vertex = graph->GetVertexCount();
    InstantiateVariables(maximum_vertex);
    graph = graph;
    vertex_count_ = graph->GetVertexCount();
    
    initializeSearch();
}

BreadthFirstSearch::BreadthFirstSearch(GraphWithMatrix *graph) {
    int maximum_vertex = graph->GetVertexCount();
    InstantiateVariables(maximum_vertex);
    graph_with_matrix_ = graph;
    vertex_count_ = graph_with_matrix_->GetVertexCount();
    
    initializeSearch();
}

void BreadthFirstSearch::InstantiateVariables(int maximum_vertex) {
    processed = new bool[maximum_vertex];
    discovered = new bool[maximum_vertex];
    parent = new int[maximum_vertex];
    colors = new Color[maximum_vertex];
}

void BreadthFirstSearch::ApplyBFS(int start ) {
    if(graph != nullptr) {
        ApplyBFSWithList(start);
    }
    else if(graph_with_matrix_ != nullptr) {
        ApplyBFSWithMatrix(start);
    }
}

void BreadthFirstSearch::ApplyBFSWithList(int start) {
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

void BreadthFirstSearch::ApplyBFSWithMatrix(int start) {
    queue<int> q;   /* queue of vertices to visit */
    int v;          /* current vertex */
    int y;          /* successor vertex */
    int *p;    /* temporary pointer */
    
    initializeSearch();
    
    q.push(start);
    discovered[start] = true;
    
    while (!q.empty()) {
        v = q.front();
        q.pop();
        processVertexEarly(v);
        processed[v] = true;
        p = graph_with_matrix_->GetEdges()[v];
        
        for (int i = 0; i < vertex_count_; i++) {
            
            if(p[i] == 0) continue;
            y = i;
            if(!processed[y] || graph_with_matrix_->IsDirected()) {
                processEdge(v, y);
            }
            if(!discovered[y]) {
                q.push(y);
                discovered[y] = true;
                parent[y] = v;
            }
        }
        processVertexLate(v);
    }
}

void BreadthFirstSearch::findConnectedComponents() {
    int c = 0; /* component number */
    
    initializeSearch();
    
    for(int i =0; i < vertex_count_; i++) {
        if(!discovered[i]) {
            c = c+1;
            cout << "Component " << c << ": ";
            ApplyBFS(i);
            cout << endl;
        }
    }
}


void BreadthFirstSearch::initializeSearch() {
    
    for(int i =0; i < vertex_count_; i++) {
        processed[i] = discovered[i] = false;
        parent[i] = -1;
    }
}

void BreadthFirstSearch::applyTwoColoringGrphs() {
    
    for(int i =0; i < vertex_count_; i++) {
        colors[i] = UNCOLORED;
    }
    
    initializeSearch();
    
    bipartite = true;
    
    for (int i = 0; i < vertex_count_; i++) {
        if(!discovered[i]) {
            colors[i] = WHITE;
            ApplyBFS(i);
        }
    }
}

void BreadthFirstSearch::processEdge(int v, int w) {
    
    cout << "process edge " << v << " " << w << endl;
    
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

void BreadthFirstSearch::processVertexEarly(int v) {
    cout << "processed vertex " << v << endl;
}

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
