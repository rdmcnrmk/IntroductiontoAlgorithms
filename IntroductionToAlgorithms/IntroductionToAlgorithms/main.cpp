//
//  main.cpp
//  IntroductionToAlgorithms
//
//  Created by Erdem Can Irmak on 9/26/16.
//  Copyright © 2016 Erdem Can Irmak. All rights reserved.
//

#include <iostream>
#include "InsertionSort.h"

int main(int argc, const char * argv[]) {
    int arr[] = { -11, -3, 9, 17, 42, 54, 54, 602, 999 };
    InsertionSort *insertionSort = new InsertionSort();
    insertionSort->Print(insertionSort->Run(arr, 9), 9);
    
    return 0;
}
