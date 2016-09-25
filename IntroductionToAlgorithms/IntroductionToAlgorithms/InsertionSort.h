//
//  InsertionSort.h
//  IntroductionToAlgorithms
//
//  Created by Erdem Can Irmak on 9/26/16.
//  Copyright © 2016 Erdem Can Irmak. All rights reserved.
//

#ifndef InsertionSort_h
#define InsertionSort_h

#include <stdio.h>

#include <iostream>

using namespace std;

class InsertionSort {
    
public:
    InsertionSort();
    int *Run(int *arr, int size);
    void Print(int *arr, int size);
};

#endif /* InsertionSort_h */
