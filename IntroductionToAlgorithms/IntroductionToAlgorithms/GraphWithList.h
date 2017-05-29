//
//  GraphWithList.h
//  IntroductionToAlgorithms
//
//  Created by Erdem Can Irmak on 5/22/17.
//  Copyright © 2017 Erdem Can Irmak. All rights reserved.
//

#ifndef GraphWithList_h
#define GraphWithList_h

#include <vector>

/*#define MAXV 1000 /* maximum number of vertices

struct EdgeNode{
    int value;
    int weight;
    struct EdgeNode *next;
};

class GraphWithList {

public:
    GraphWithList(const int verticesCount, const bool directed);
    void AddEdge(int v, int w, bool directed);
    void PrintGraph();
    int VertexCount();
    EdgeNode** GetEdges();
    bool IsDirected();
    
private:
    int nvertices;
    int nedges;
    bool directed;
    EdgeNode* edges[MAXV+1];
    int degree[MAXV+1];
};

GraphWithList::GraphWithList(int verticesCount, bool directed) {
    this->directed = directed;
    this->nedges = 0;
    this->nvertices = verticesCount;
    
    for(int i = 0; i <= MAXV; i++) this->degree[i] = 0;
    for(int i = 0; i <= MAXV; i++) this->edges[i] = NULL;
}

int GraphWithList::VertexCount() { return nedges; }
EdgeNode** GraphWithList::GetEdges() { return edges; }
bool GraphWithList::IsDirected() { return directed; }

void GraphWithList::AddEdge(int v, int w, bool directed) {
    EdgeNode *p; /* temporary pointer 
    p = new EdgeNode();
    p->weight = NULL;
    p->value = w;
    p->next = edges[v];
    
    edges[v] = p;
    degree[v]++;
    
    if(!directed) {
        AddEdge(w, v, true);
    } else {
        nedges++;
    }
}

void GraphWithList::PrintGraph() {
    EdgeNode *p;
    
    for(int i = 0; i < nvertices; i++) {
        cout << i << ": ";
        p = edges[i];
        while (p != NULL) {
            cout << p->value << " ";
            p = p->next;
        }
        cout << endl;
    }
}*/

#endif /* GraphWithList_h */
