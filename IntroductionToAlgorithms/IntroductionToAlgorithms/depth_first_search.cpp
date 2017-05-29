//
//  depth_first_search.cpp
//  IntroductionToAlgorithms
//
//  Created by Erdem Can Irmak on 5/27/17.
//  Copyright © 2017 Erdem Can Irmak. All rights reserved.
//

#include "depth_first_search.h"

DepthFirstSearch::DepthFirstSearch(GraphWithList *graph) {
    int maximum_vertex = graph->GetVertexCount();
    InstantiateDFSVariables(maximum_vertex);
    graph_with_list_ = graph;
    InitializeSearch();
}

DepthFirstSearch::DepthFirstSearch(GraphWithMatrix *graph) {
    int maximum_vertex = graph->GetVertexCount();
    InstantiateDFSVariables(maximum_vertex);
    graph_with_matrix_ = graph;
    InitializeSearch();
}

void DepthFirstSearch::InstantiateDFSVariables(int maximum_vertex) {
    processed_ = new bool[maximum_vertex+1];
    discovered_ = new bool[maximum_vertex+1];
    parent_ = new int[maximum_vertex+1];
    entry_time_ = new int[maximum_vertex+1];
    exit_time_ = new int[maximum_vertex+1];
    reachable_ancestor_ = new int[maximum_vertex+1];
    tree_out_degree_ = new int[maximum_vertex+1];
    finished_ = false;
}

void DepthFirstSearch::ApplyDFS(int start) {
    if(graph_with_matrix_ != nullptr) {
        ApplyDFSWithMatrix(start);
    }
    else if(graph_with_list_ != nullptr) {
        ApplyDFSWithList(start);
    }
}

void DepthFirstSearch::ApplyDFSWithList(int start) {
    EdgeNode *p;
    int y;
    
    discovered_[start] = true;
    time_ = time_ + 1;
    entry_time_[start] = time_;
    
    ProcessVertexEarly(start);
    p = graph_with_list_->GetEdges()[start];
    
    while (p != NULL) {
        y = p->value;
        if(discovered_[y] == false) {
            parent_[y] = start;
            ProcessEdge(start, y);
            ApplyDFS(y);
        }
        else if(!processed_[y] || graph_with_list_->IsDirected()) {
            ProcessEdge(start, y);
        }
        
        p = p->next;
    }
    
    ProcessVertexLate(start);
    time_ = time_ + 1;
    exit_time_[start] = time_;
}

void DepthFirstSearch::ApplyDFSWithMatrix(int start) {
    int y;
    int *p;
    
    discovered_[start] = true;
    time_ = time_ + 1;
    entry_time_[start] = time_;
    
    ProcessVertexEarly(start);
    p = graph_with_matrix_->GetEdges()[start];
    
    for (int i = 0; i < graph_with_matrix_->GetVertexCount(); i++) {
        if(p[i] == 0) continue;
        y = i;
        if(discovered_[y] == false) {
            parent_[y] = start;
            ProcessEdge(start, y);
            ApplyDFS(y);
        }
        else if(!processed_[y] || graph_with_matrix_->IsDirected()) {
            ProcessEdge(start, y);
        }
    }
    
    ProcessVertexLate(start);
    time_ = time_ + 1;
    exit_time_[start] = time_;
}

void DepthFirstSearch::InitializeSearch() {
    
    int v_count = 0;
    if(graph_with_list_ != nullptr) {
        v_count = graph_with_list_->GetVertexCount();
    }
    else if(graph_with_matrix_ != nullptr) {
        v_count = graph_with_matrix_->GetVertexCount();
    }
    
    for(int i =0; i < v_count; i++) {
        processed_[i] = discovered_[i] = false;
        parent_[i] = -1;
        entry_time_[i] = 0;
        exit_time_[i] = 0;
    }
    
    time_ = 0;
}

void DepthFirstSearch::ProcessVertexEarly(int v) {
    cout << "processed vertex " << v << endl;
    reachable_ancestor_[v] = v;
}

void DepthFirstSearch::ProcessEdge(int v, int w) {
    cout << "process edge " << v << " " << w << endl;
    if(discovered_[w] && parent_[v] != w) {
        cout << "Cycle from " << w << " " << v  << endl;
        finished_ = true;
    }
    
    int edgeClass; /* edge class */
    edgeClass = EdgeClassification(v, w);
    
    if(edgeClass == TREE) {
        tree_out_degree_[v] = tree_out_degree_[v] + 1;
    }
    if(edgeClass == BACK && parent_[v] != w) {
        if(entry_time_[w] < entry_time_[reachable_ancestor_[v]]) {
            reachable_ancestor_[v] = w;
        }
    }
    
}

void DepthFirstSearch::ProcessVertexLate(int v) {
    
}

int DepthFirstSearch::EdgeClassification(int v, int w) {
    if(parent_[w] == v) return TREE;
    if(discovered_[w] && !processed_[w]) return BACK;
    if(processed_[w] && (entry_time_[w] > entry_time_[v])) return FORWARD;
    if(processed_[w] && (entry_time_[w] < entry_time_[v])) return CROSS;
    
    return DEFAULT;
}
