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

int main(int argc, const char * argv[]) {
    //int arr[] = { 602,  -3, 17, 999, 42, -11, 54, 54, 9 };
    //int arr[] = { 602,  -3, 17, 999 };
    //InsertionSort *insertionSort = new InsertionSort();
    //insertionSort->Print(insertionSort->Run(arr, 9), 9);
    
    /*MergeSort *mergeSort = new MergeSort();
    mergeSort->Run(arr, 0, 8);
    insertionSort->Print(arr, 9);*/
    
    int arr[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};

    MaximumSubArray *maxSub = new MaximumSubArray();
    //int *arr = maxSub->CreateInput();
    MinMaxSum *result = maxSub->Run(arr, 0, 15);
    std::cout << result->min << " " << result->max << " " << result->sum << std::endl;
    
    return 0;
}
