//
//  GraphBase.h
//  IntroductionToAlgorithms
//
//  Created by Erdem Can Irmak on 5/26/17.
//  Copyright © 2017 Erdem Can Irmak. All rights reserved.
//

#ifndef GRAPH_BASE_H_
#define GRAPH_BASE_H_

struct EdgeNode{
    int value;
    int weight;
    struct EdgeNode *next;
};

class GraphBase {
public:
    GraphBase(int vertices_count, bool directed);
    virtual ~GraphBase() {};
    
    virtual void AddEdge(int v, int w) = 0;
    virtual void PrintGraph() = 0;
    inline int GetVertexCount();
    inline int GetEdgeCount();
    inline bool IsDirected();

protected:
    int number_of_vertices;
    int number_of_edges;
    bool is_directed;
    int *degree;
    
    virtual void AddEdgeHelper(int v, int w, bool directed) = 0;
};

inline int GraphBase::GetVertexCount() { return number_of_vertices; }
inline int GraphBase::GetEdgeCount() { return number_of_edges; }
inline bool GraphBase::IsDirected() { return is_directed; }

#endif /* GRAPH_BASE_H_ */
