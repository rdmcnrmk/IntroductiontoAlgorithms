//
//  graph_base.cpp
//  IntroductionToAlgorithms
//
//  Created by Erdem Can Irmak on 5/26/17.
//  Copyright © 2017 Erdem Can Irmak. All rights reserved.
//

#include <stdio.h>
#include "graph_base.h"

GraphBase::GraphBase(int vertices_count, bool directed) {
    degree = new int[vertices_count];
    number_of_vertices = vertices_count;
    number_of_edges = 0;
    is_directed = directed;
}

