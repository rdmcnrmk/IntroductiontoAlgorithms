//
//  main.cpp
//  IntroductionToAlgorithms
//
//  Created by Erdem Can Irmak on 9/26/16.
//  Copyright © 2016 Erdem Can Irmak. All rights reserved.
//

#include <iostream>
#include "InsertionSort.h"
#include "MergeSort.h"
#include "MaximumSubArray.h"
#include "SquareMatrixMultiply.h"
#include "StrassenAlgorithm.h"

#include "GraphWithList.h"
#include "DepthFirstSearch.h"
#include "BreadthFirstSearch.h"
#include "WeightedGraphAlgorithms.h"

int main(int argc, const char * argv[]) {
    //int arr[] = { 602,  -3, 17, 999, 42, -11, 54, 54, 9 };
    //int arr[] = { 602,  -3, 17, 999 };
    //InsertionSort *insertionSort = new InsertionSort();
    //insertionSort->Print(insertionSort->Run(arr, 9), 9);
    
    /*MergeSort *mergeSort = new MergeSort();
    mergeSort->Run(arr, 0, 8);
    insertionSort->Print(arr, 9);*/
    
    //int arr[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};

    /*MaximumSubArray *maxSub = new MaximumSubArray();
    //int *arr = maxSub->CreateInput();
    MinMaxSum *result = maxSub->Run(arr, 0, 15);
    std::cout << result->min << " " << result->max << " " << result->sum << std::endl;*/
    
    /*SquareMatrixMultiply *multiply = new SquareMatrixMultiply();
    StrassenAlgorithm *strassen = new StrassenAlgorithm();
    Matrix2D<int> *in1 = multiply->CreateInput1();
    Matrix2D<int> *in2 = multiply->CreateInput1();
    
    Matrix2D<int> *result = strassen->Run(in1, in2);
    in1->Print();
    in2->Print();
    result->Print();*/
    
    GraphWithList g(6, false);
    g.AddEdge(0, 1, false);
    g.AddEdge(1, 2, false);
    g.AddEdge(2, 3, false);
    g.AddEdge(3, 4, false);
    g.AddEdge(4, 0, false);
    g.AddEdge(1, 4, false);
    g.AddEdge(0, 5, false);
    g.PrintGraph();
    
    //BreadthFirstSearch *bfs = new BreadthFirstSearch(&g, 4);
    //bfs->applyTwoColoringGrphs();
    
    DepthFirstSearch *dfs = new DepthFirstSearch(&g);
    dfs->ApplyDFS(0);
    //bfs->ApplyBFS(2);
    //bfs->findpath(1, 3);
    //DepthFirstSearch::DFSWAdjacencyListRecursive(&g, 2);
    
    return 0;
}
