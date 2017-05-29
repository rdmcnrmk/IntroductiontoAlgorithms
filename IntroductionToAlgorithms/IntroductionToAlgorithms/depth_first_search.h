//
//  DepthFirstSearch.h
//  IntroductionToAlgorithms
//
//  Created by Erdem Can Irmak on 5/22/17.
//  Copyright © 2017 Erdem Can Irmak. All rights reserved.
//

#ifndef DepthFirstSearch_h
#define DepthFirstSearch_h

#include "graph_with_list.h"
#include "graph_with_matrix.h"

using namespace std;

enum EdgeClassTypes { TREE, BACK, FORWARD, CROSS, DEFAULT };

class DepthFirstSearch {

public:
    DepthFirstSearch(GraphWithList *graph);
    DepthFirstSearch(GraphWithMatrix *graph);
    
    void ApplyDFS(int start);
    
private:
    GraphWithList   *graph_with_list_;
    GraphWithMatrix *graph_with_matrix_;
    
    bool            *processed_;
    bool            *discovered_;
    bool            finished_;
    
    int             *parent_;
    int             *entry_time_;
    int             *exit_time_;
    int             *reachable_ancestor_;
    int             *tree_out_degree_;
    int             time_;
    
    void ProcessVertexEarly(int v);
    void ProcessEdge(int v, int w);
    void ProcessVertexLate(int v);
    void InitializeSearch();
    void InstantiateDFSVariables(int maximum_vertex);
    int  EdgeClassification(int v, int w);
    
    void ApplyDFSWithMatrix(int start);
    void ApplyDFSWithList(int start);
    
};





#endif /* DepthFirstSearch_h */
