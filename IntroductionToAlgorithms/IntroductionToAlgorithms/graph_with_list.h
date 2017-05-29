//
//  graph_with_list.hpp
//  IntroductionToAlgorithms
//
//  Created by Erdem Can Irmak on 5/26/17.
//  Copyright © 2017 Erdem Can Irmak. All rights reserved.
//

#ifndef GRAPH_WITH_LIST_H
#define GRAPH_WITH_LIST_H

#include <stdio.h>
#include <vector>
#include <iostream>

#include "graph_base.h"

using namespace std;


class GraphWithList: public GraphBase {
    
public:
    GraphWithList(const int verticesCount, const bool directed);
    ~GraphWithList() override;
    void AddEdge(int v, int w) override;
    void PrintGraph() override;
    EdgeNode** GetEdges();
    
protected:
    EdgeNode** edges;
    void AddEdgeHelper(int v, int w, bool directed) override;
};

#endif /* GRAPH_WITH_LIST_H */
