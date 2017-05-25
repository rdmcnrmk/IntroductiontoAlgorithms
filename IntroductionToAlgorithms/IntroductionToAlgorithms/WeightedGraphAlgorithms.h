//
//  WeightedGraphAlgorithms.h
//  IntroductionToAlgorithms
//
//  Created by Erdem Can Irmak on 5/25/17.
//  Copyright © 2017 Erdem Can Irmak. All rights reserved.
//

#ifndef WeightedGraphAlgorithms_h
#define WeightedGraphAlgorithms_h

#include "GraphWithList.h"

struct setUnion {
    
};

class WeightedGraphAlgorithms {
public:
    
    static void prims(GraphWithList *graph, int start);
    static void kruskal(GraphWithList *graph);
    
private:
    
};

void WeightedGraphAlgorithms::prims(GraphWithList *g, int start) {
    
    EdgeNode *p;            /* temporary pointer */
    bool intree[MAXV+1];    /* is the vertex in the tree yet? */
    int distance[MAXV+1];   /* cost of adding to tree */
    int parent[MAXV+1];     /* parent of the vertex */
    int v;                  /* current vertex to process */
    int w;                  /* candidate next vertex */
    int weight;             /* edge weight */
    int dist;               /* best current distance from start */
    
    for (int i = 1; i <= g->VertexCount(); i++) { /* initialize arrays */
        intree[i] = false;
        distance[i] = INT_MAX;
        parent[i] = -1;
    }
    
    distance[start] = 0;
    v = start;
    
    while (intree[v] == false) {
        intree[v] = true;
        p = g->GetEdges()[v];
        while(p != nullptr) {
            w = p->value;
            weight = p->weight;
            if(distance[w] > weight && intree[w] == false) {
                distance[w] = weight;
                parent[w] = v;
            }
            p = p->next;
        }
        v = 1;
        dist = INT_MAX;
        for(int i = 1; i < g->VertexCount(); i++) {
            if(intree[i] == false && dist < distance[i]) {
                dist = distance[i];
                v = i;
            }
        }
    }
}

void WeightedGraphAlgorithms::kruskal(GraphWithList *g) {
    
}

#endif /* WeightedGraphAlgorithms_h */
