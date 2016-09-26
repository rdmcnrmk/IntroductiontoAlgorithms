//
//  MaximumSubArray.h
//  IntroductionToAlgorithms
//
//  Created by Erdem Can Irmak on 9/26/16.
//  Copyright © 2016 Erdem Can Irmak. All rights reserved.
//

#ifndef MaximumSubArray_h
#define MaximumSubArray_h

#include <stdio.h>

#include <iostream>

using namespace std;

class MinMaxSum {
public:
    int min;
    int max;
    int sum;
    MinMaxSum(int min, int max, int sum) {
        this->min = min;
        this->max = max;
        this->sum = sum;
    }
};

class MaximumSubArray {
    
public:
    MaximumSubArray();
    int *CreateInput();
    MinMaxSum *Run(int *arr, int low, int high);
    void Print(int *arr, int size);
    
private:
    MinMaxSum *FindMaximumCrossingSubarray(int *arr, int low, int mid, int high);
};


#endif /* MaximumSubArray_h */
