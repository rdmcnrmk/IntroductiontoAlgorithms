//
//  DijkstraWithMatrix.h
//  IntroductionToAlgorithms
//
//  Created by Erdem Can Irmak on 7/21/17.
//  Copyright © 2017 Erdem Can Irmak. All rights reserved.
//

#ifndef DijkstraWithMatrix_h
#define DijkstraWithMatrix_h

#include <vector>

class DijkstraWithMatrix {
    static int FindMinimumDistance(int dist[], bool spt[], int size);
public:
    static vector<vector<int>> CreateTwoDimGraph();
    static void ApplyDijkstra(vector<vector<int>> g, int s);
};

vector<vector<int>> DijkstraWithMatrix::CreateTwoDimGraph(){
    vector<vector<int>> graph = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };
    
    return graph;
}

void DijkstraWithMatrix::ApplyDijkstra(vector<vector<int>> g, int s) {
    bool sptSet[(int)g.size()];
    int dist[(int)g.size()];
    
    for (int i = 0; i < g.size(); i++) {
        sptSet[i] = false;
        dist[i] = INT_MAX;
    }
    
    dist[s] = 0;
    
    for (int i = 0 ; i < g.size()-1; i++) {
        int u = FindMinimumDistance(dist, sptSet, (int)g.size());
        
        sptSet[u] = true;
        
        for (int v = 0;  v < g.size(); v++) {
            if(!sptSet[v] && g[v][u] != 0 && dist[u] != INT_MAX && dist[u] + g[u][v] < dist[v]) {
                dist[v] = dist[u] + g[u][v];
            }
        }
    }
    
    for (int i = 0; i < g.size(); i++) {
        cout << dist[i] << endl;
    }
}

int DijkstraWithMatrix::FindMinimumDistance(int dist[], bool spt[], int size) {
    int result = INT_MAX;
    int res = -1;
    for (int i = 0; i < size; i++) {
        if(result >= dist[i] && !spt[i]) {
            result = dist[i];
            res = i;
        }
    }
    return res;
}

#endif /* DijkstraWithMatrix_h */
