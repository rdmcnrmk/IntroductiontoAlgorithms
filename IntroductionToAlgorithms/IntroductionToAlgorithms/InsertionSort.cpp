//
//  InsertionSort.cpp
//  IntroductionToAlgorithms
//
//  Created by Erdem Can Irmak on 9/26/16.
//  Copyright © 2016 Erdem Can Irmak. All rights reserved.
//

#include "InsertionSort.h"

InsertionSort::InsertionSort() {
    
}


int *InsertionSort::Run(int *arr, int size){
    
    for (int i = 1; i < size; i++) {
        int indexVal = arr[i];
        int index = i-1;
        
        while (arr[index] > indexVal && index >= 0) {
            
            arr[index+1] = arr[index];
            index--;
        }
        arr[index+1] = indexVal;
    }
    
    return arr;
}

void InsertionSort::Print(int *arr, int size) {
    
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << endl;
}