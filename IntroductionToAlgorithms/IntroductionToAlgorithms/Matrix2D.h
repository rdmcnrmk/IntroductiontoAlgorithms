//
//  Matrix2D.h
//  IntroductionToAlgorithms
//
//  Created by Erdem Can Irmak on 9/28/16.
//  Copyright © 2016 Erdem Can Irmak. All rights reserved.
//

#ifndef Matrix2D_h
#define Matrix2D_h

#include <stdio.h>
#include <vector>
#include <iostream>

template <typename T>

class Matrix2D {
    std::vector<T> inner_;
    unsigned int dimx_, dimy_;
    
public:
    Matrix2D (unsigned int dimx, unsigned int dimy);
    
    int GetRowCount();
    int GetColumnCount();
    
    T& operator()(unsigned int x, unsigned int y);
    void Print();
    Matrix2D<T> *MatrixPartition(unsigned int minX, unsigned int maxX, unsigned int minY, unsigned int maxY);
    Matrix2D<T> *Sum(Matrix2D<T> *a, Matrix2D<T> *b);
    Matrix2D<T> *Subtract(Matrix2D<T> *a, Matrix2D<T> *b);
};

#endif /* Matrix2D_h */
