//
//  TopologicalSort.h
//  IntroductionToAlgorithms
//
//  Created by Erdem Can Irmak on 7/20/17.
//  Copyright © 2017 Erdem Can Irmak. All rights reserved.
//

#ifndef TopologicalSort_h
#define TopologicalSort_h

#include <stack>
#include <vector>
#include <queue>

#include "GraphWithLists.h"

using namespace std;

class TopologicalSort {
    static void TSHelper(int start, GraphWithLists *graph, bool *visited, stack<int> &s);
    static void TSAllHelper(GraphWithLists *graph, bool visited[], vector<int>& res);
public:
    static void ApplyTS(GraphWithLists *graph);
    static void ApplyTSAll(GraphWithLists *graph);
    static void ApplyTSKahn(GraphWithLists *graph);
};

void TopologicalSort::TSHelper(int start, GraphWithLists *graph, bool *visited, stack<int> &s) {
    visited[start] = true;
    
    AdjListNode *node = graph->vertices[start].head;
    
    while(node != nullptr) {
        
        if(!visited[node->value]) {
            TSHelper(node->value, graph, visited, s);
        }
        
        node = node->next;
    }
    
    s.push(start);
}

void TopologicalSort::ApplyTS(GraphWithLists *graph) {
    
    stack<int> s;
    bool *visited = new bool[graph->vertexCount];
    
    for (int i =0; i < graph->vertexCount; i++) {
        visited[i] = false;
    }
    
    for (int i = 0; i < graph->vertexCount; i++) {
        if(!visited[i]) {
            TSHelper(i, graph, visited, s);
        }
    }
    
    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
}

void TopologicalSort::ApplyTSAll(GraphWithLists *graph) {
    bool *visited = new bool[graph->vertexCount];
    
    for (int i = 0; i < graph->vertexCount; i++) {
        visited[i] = false;
    }
    
    vector<int> res;
    
    TSAllHelper(graph, visited, res);
}

void TopologicalSort::TSAllHelper(GraphWithLists *graph, bool* visited, vector<int>& res) {
    
    bool flag = false;
    
    for (int i = 0; i < graph->vertexCount; i++) {
        
        if(visited[i] == false && graph->inDegree[i] == 0) {
            AdjListNode *node = graph->vertices[i].head;
            
            while (node != nullptr) {
                graph->inDegree[node->value]--;
                node = node->next;
            }
            
            res.push_back(i);
            visited[i] = true;
            TSAllHelper(graph, visited, res);
            visited[i] = false;
            
            res.erase(res.end()-1);
            
            node = graph->vertices[i].head;
            
            while (node != nullptr) {
                graph->inDegree[node->value]++;
                node = node->next;
            }
            
            flag = true;
        }
    }
    
    if(!flag) {
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
    }
}

void TopologicalSort::ApplyTSKahn(GraphWithLists *graph) {
    
    queue<int> q;
    
    for (int i = 0; i < graph->vertexCount; i++) {
        if(graph->inDegree[i] == 0) {
            q.push(i);
        }
    }
    
    vector<int> result;
    int counter = 0;
    
    while (!q.empty()) {
        
        int u = q.front();
        q.pop();
        result.push_back(u);
        
        AdjListNode *node = graph->vertices[u].head;
        
        while (node != nullptr) {
            graph->inDegree[node->value]--;
            if(graph->inDegree[node->value] == 0) {
                q.push(node->value);
            }
            node = node->next;
        }
        
        counter++;
    }
    
    if(counter != graph->vertexCount) {
        cout << "graph is not acyclic" << endl;
        return;
    }
    
    for (int i = 0; i < graph->vertexCount; i++) {
        cout << result[i] << " ";
    }
    
    cout << endl;
}

#endif /* TopologicalSort_h */
