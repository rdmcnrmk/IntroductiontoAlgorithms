//
//  MergeSort.h
//  IntroductionToAlgorithms
//
//  Created by Erdem Can Irmak on 9/26/16.
//  Copyright © 2016 Erdem Can Irmak. All rights reserved.
//

#ifndef MergeSort_h
#define MergeSort_h

#include <stdio.h>

#include <iostream>

using namespace std;

class MergeSort {
    
public:
    MergeSort();
    void Run(int *arr, int p, int r);
    void Print(int *arr, int size);
    
private:
    void Merge(int *arr, int p, int q, int r);
};

#endif /* MergeSort_h */
