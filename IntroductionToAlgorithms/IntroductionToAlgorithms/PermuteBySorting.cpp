//
//  PermuteBySorting.cpp
//  IntroductionToAlgorithms
//
//  Created by Erdem Can Irmak on 10/8/16.
//  Copyright © 2016 Erdem Can Irmak. All rights reserved.
//

#include "PermuteBySorting.h"


PermuteBySorting::PermuteBySorting() {
    
}

int *PermuteBySorting::CreateInput1() {
 
    int *v = new int[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    return v;
}

void PermuteBySorting::Run(int *v, int size) {
    
    int *p[size];
    int *result[size];
    for (int i = 0; i < size; i++) {
        (*p)[i] = rand() % (size*size*size);
    }
    
    
}