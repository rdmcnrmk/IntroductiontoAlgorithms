//
//  MaximumSubArray.cpp
//  IntroductionToAlgorithms
//
//  Created by Erdem Can Irmak on 9/26/16.
//  Copyright © 2016 Erdem Can Irmak. All rights reserved.
//

#include "MaximumSubArray.h"
#include <limits.h>

MaximumSubArray::MaximumSubArray() {
    
}

int *MaximumSubArray::CreateInput() {
    int arr[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    return arr;
}

MinMaxSum *MaximumSubArray::FindMaximumCrossingSubarray(int *arr, int low, int mid, int high){
    int leftSum = INT_MIN;
    int sum = 0;
    int maxLeft = 0;
    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        if(sum > leftSum) {
            leftSum = sum;
            maxLeft = i;
        }
    }
    
    int rightSum = INT_MIN;
    sum = 0;
    int maxRight = 0;
    
    for (int i = mid+1; i <= high; i++) {
        sum += arr[i];
        if(sum > rightSum) {
            rightSum = sum;
            maxRight = i;
        }
    }
    
    return new MinMaxSum(maxLeft, maxRight, leftSum + rightSum);
}

MinMaxSum *MaximumSubArray::Run(int *arr, int low, int high) {
    
    if(high == low) {
        return new MinMaxSum(low, high, arr[low]);
    }
    else {
        int mid = (low + high) / 2;
        MinMaxSum *left = Run(arr, low, mid);
        MinMaxSum *right = Run(arr, mid+1, high);
        MinMaxSum *cross = FindMaximumCrossingSubarray(arr, low, mid, high);
        
        if(left->sum >= right->sum && left->sum >= cross->sum) {
            return left;
        }
        else if(right->sum >= left->sum && right->sum >= cross->sum) {
            return right;
        }
        else {
            return cross;
        }
    }
}
