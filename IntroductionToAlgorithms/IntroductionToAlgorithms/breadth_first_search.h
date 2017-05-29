//
//  BreadthFirstSearch.h
//  IntroductionToAlgorithms
//
//  Created by Erdem Can Irmak on 5/23/17.
//  Copyright © 2017 Erdem Can Irmak. All rights reserved.
//

#ifndef BreadthFirstSearch_h
#define BreadthFirstSearch_h

#include <queue>

#include "graph_with_list.h"
#include "graph_with_matrix.h"

using namespace std;

enum Color { WHITE, BLACK, UNCOLORED };


class BreadthFirstSearch {
public:
    BreadthFirstSearch(GraphWithList *graph);
    BreadthFirstSearch(GraphWithMatrix *graph);
    
    void ApplyBFS(int start);
    void findpath(int start, int end);
    void findConnectedComponents();
    void applyTwoColoringGrphs();
private:
    
    bool        *processed;
    bool        *discovered;
    int         *parent;
    bool        bipartite;
    int         vertex_count_;
    
    Color *colors;
    GraphWithList *graph;
    GraphWithMatrix *graph_with_matrix_;
    
    void processVertexEarly(int v);
    void processEdge(int v, int w);
    void processVertexLate(int v);
    void initializeSearch();
    void InstantiateVariables(int maximum_vertex);
    
    void ApplyBFSWithList(int start);
    void ApplyBFSWithMatrix(int start);
    
};

#endif /* BreadthFirstSearch_h */
