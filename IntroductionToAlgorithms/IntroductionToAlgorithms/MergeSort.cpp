//
//  MergeSort.cpp
//  IntroductionToAlgorithms
//
//  Created by Erdem Can Irmak on 9/26/16.
//  Copyright © 2016 Erdem Can Irmak. All rights reserved.
//

#include "MergeSort.h"
#include <limits.h>

MergeSort::MergeSort() {
    
}

void MergeSort::Run(int *arr, int p, int r) {
    if(p < r) {
        int q = (p + r) / 2;
        Run(arr, p, q);
        Run(arr, q+1, r);
        Merge(arr, p, q, r);
    }
}

void MergeSort::Print(int *arr, int size) {
    
}

void MergeSort::Merge(int *arr, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    
    int L[n1+1];
    int R[n2+1];
    
    int i = 0;
    for (; i < n1; i++) {
        L[i] = arr[p + i];
    }
    
    int j = 0;
    for (; j < n2; j++) {
        R[j] = arr[q + j+1];
    }
    
    L[i] = INT_MAX;
    R[j] = INT_MAX;
    
    i = 0;
    j = 0;
    
    for (int k = p; k <= r; k++) {
        if(L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
    }
}

