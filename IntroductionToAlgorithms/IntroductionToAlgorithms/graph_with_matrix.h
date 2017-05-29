//
//  graph_with_matrix.hpp
//  IntroductionToAlgorithms
//
//  Created by Erdem Can Irmak on 5/27/17.
//  Copyright © 2017 Erdem Can Irmak. All rights reserved.
//

#ifndef GRAPH_WITH_MATRIX_H
#define GRAPH_WITH_MATRIX_H

#include <stdio.h>
#include <vector>
#include <iostream>

#include "graph_base.h"

using namespace std;


class GraphWithMatrix: public GraphBase {
    
public:
    GraphWithMatrix(const int verticesCount, const bool directed);
    ~GraphWithMatrix() override;
    void AddEdge(int v, int w) override;
    void PrintGraph() override;
    int** GetEdges();
    
protected:
    int** edges;
    void AddEdgeHelper(int v, int w, bool directed) override;
};


#endif /* GRAPH_WITH_MATRIX_H */
