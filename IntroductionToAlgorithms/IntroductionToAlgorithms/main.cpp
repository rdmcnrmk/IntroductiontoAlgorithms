//
//  main.cpp
//  IntroductionToAlgorithms
//
//  Created by Erdem Can Irmak on 9/26/16.
//  Copyright © 2016 Erdem Can Irmak. All rights reserved.
//

#include <iostream>
//#include "InsertionSort.h"
//#include "MergeSort.h"
//#include "MaximumSubArray.h"
//#include "SquareMatrixMultiply.h"
//#include "StrassenAlgorithm.h"

//#include "depth_first_search.h"
//#include "breadth_first_search.h"
//#include "WeightedGraphAlgorithms.h"
//#include "graph_with_list.h"
//#include "graph_with_matrix.h"
//#include "ActivitySelectionProblem.h"
//#include "EgyptianFraction.h"
#include "JobSequencingProblem.h"
//#include "GraphWithLists.h"
//#include "DFS.h"
//#include "TopologicalSort.h"
//#include "DijkstraWithMatrix.h"
//#include "BasicDPProblem.h"
//#include "Fibonacci.h"
//#include "BinomialCoefficient.h"
//#include "LongestCommonSubsequence.h"
#include "LargestSubArray.h"
#include "UglyNumbers.h"
#include "MaxOnesSubMatrix.h"


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
    
    /*GraphWithMatrix g(6, false);
    g.AddEdge(0, 1);
    g.AddEdge(1, 2);
    g.AddEdge(2, 3);
    g.AddEdge(3, 4);
    g.AddEdge(4, 0);
    g.AddEdge(1, 4);
    g.AddEdge(0, 5);
    g.PrintGraph();
    
    
    BreadthFirstSearch *bfs = new BreadthFirstSearch(&g);
    bfs->ApplyBFS(0);
    
    //DepthFirstSearch *dfs = new DepthFirstSearch(&g);
    //dfs->ApplyDFS(0);
    //bfs->ApplyBFS(2);
    //bfs->findpath(1, 3);
    //DepthFirstSearch::DFSWAdjacencyListRecursive(&g, 2);
    */
    
    /*Activity arr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}};
    int n = sizeof(arr)/sizeof(arr[0]);
    ActivitySelectionProblem* asp = new ActivitySelectionProblem(arr, n);
    asp->Run();*/
    
    //EgyptianFraction *ef = new EgyptianFraction(6, 14);
    //ef->Run();
    
    //JobSequencingProblem *jsp = new JobSequencingProblem();
    //jsp->Run();
    
    /*int V = 6;
    GraphWithLists *graph = new GraphWithLists(V);
    graph->AddEdge(5, 2, 1, 1);
    graph->AddEdge(5, 0, 1, 1);
    graph->AddEdge(4, 0, 1, 1);
    graph->AddEdge(4, 1, 1, 1);
    graph->AddEdge(2, 3, 1, 1);
    graph->AddEdge(3, 1, 1, 1);
    //graph->AddEdge(3, 4, 1, 0);
    */
    // print the adjacency list representation of the above graph
    //graph->PrintGraph();
    
    //DFS::ApplyDFS(graph, 2);
    //TopologicalSort::ApplyTSKahn(graph);
    
    //DijkstraWithMatrix::ApplyDijkstra(DijkstraWithMatrix::CreateTwoDimGraph(), 0);
    
    //BasicDPProblem *dp = new BasicDPProblem(10);
    
    /*Fibonacci *f = new Fibonacci(10);
    cout << f->FibonacciWithNaiveApproach(10) << endl;
    cout << f->FibonacciWithMemoization(10) << endl;
    cout << f->FibonacciWithTabulation(10) << endl;
    cout << f->FibonacciSpaceOptimized(10) << endl;*/
    
    /*BinomialCoefficient *bc = new BinomialCoefficient();
    cout << bc->ApplyBCNaive(5, 2) << endl;
    cout << bc->ApplyBCOverlappingS(5, 2) << endl;*/
    /*LongestCommonSubsequence *lcs = new LongestCommonSubsequence();
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    
    int m = strlen(X);
    int n = strlen(Y);
    cout << lcs->ApplyLCS(X, Y, m, n) << endl;
    cout << lcs->ApplyLCOverlappingS(X, Y, m, n) << endl;*/
    
    //new LargestSubArray();
    new UglyNumbers();
    new MaxOnesSubMatrix();
    
    return 0;
}
