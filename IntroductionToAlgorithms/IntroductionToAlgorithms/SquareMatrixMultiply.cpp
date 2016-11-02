//
//  SquareMatrixMultiply.cpp
//  IntroductionToAlgorithms
//
//  Created by Erdem Can Irmak on 9/28/16.
//  Copyright © 2016 Erdem Can Irmak. All rights reserved.
//

#include "SquareMatrixMultiply.h"


SquareMatrixMultiply::SquareMatrixMultiply() {
    
}

Matrix2D<int> *SquareMatrixMultiply::CreateInput1() {
    Matrix2D<int> *rMat = new Matrix2D<int>(4, 4);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            (*rMat)(i, j) = rand() % 4;
        }
    }
    
    return rMat;
}

Matrix2D<int> *SquareMatrixMultiply::Run(Matrix2D<int> *a, Matrix2D<int> *b) {
    
    int n = a->GetRowCount();
    Matrix2D<int> *rMat;
    
    if (n == 1) {
        rMat = new Matrix2D<int>(1, 1);
        (*rMat)(0, 0) = (*a)(0, 0) * (*b)(0, 0);
    }
    else {
        rMat = new Matrix2D<int>(n, n);
        
        
        Matrix2D<int> *c11a = Run(a->MatrixPartition(0, n/2 - 1, 0, n/2 -1), b->MatrixPartition(0, n/2 - 1, 0, n/2 -1));
        Matrix2D<int> *c11b = Run(a->MatrixPartition(0, n/2 - 1, n/2, n -1), b->MatrixPartition(n/2, n - 1, 0, n/2 -1));
        
        for (int i = 0; i < n/2; i++) {
            for (int j = 0; j < n/2; j++) {
                (*rMat)(i, j) = (*c11a)(i, j) + (*c11b)(i, j);
            }
        }
        
        Matrix2D<int> *c12a = Run(a->MatrixPartition(0, n/2 - 1, 0, n/2 -1), b->MatrixPartition(0, n/2 - 1, n/2 ,n-1));
        Matrix2D<int> *c12b = Run(a->MatrixPartition(0, n/2 - 1, n/2 ,n-1), b->MatrixPartition(n/2, n - 1, n/2 ,n-1));
        
        for (int i = 0; i < n/2; i++) {
            for (int j = 0; j < n/2; j++) {
                (*rMat)(i, n/2 + j) = (*c12a)(i, j) + (*c12b)(i, j);
            }
        }
        
        Matrix2D<int> *c21a = Run(a->MatrixPartition(n/2, n-1,  0, n/2 -1 ), b->MatrixPartition(0 , n/2-1,  0, n/2 -1));
        Matrix2D<int> *c21b = Run(a->MatrixPartition(n/2, n-1,  n/2, n-1 ), b->MatrixPartition(n/2 , n-1,  0, n/2 -1));
        
        for (int i = 0; i < n/2; i++) {
            for (int j = 0; j < n/2; j++) {
                (*rMat)(n/2 + i, j) = (*c21a)(i, j) + (*c21b)(i, j);
            }
        }
        
        Matrix2D<int> *c22a = Run(a->MatrixPartition(n/2, n-1, 0, n/2-1 ), b->MatrixPartition(0, n/2-1, n/2, n-1 ));
        Matrix2D<int> *c22b = Run(a->MatrixPartition(n/2, n-1, n/2, n-1 ), b->MatrixPartition(n/2, n-1, n/2, n-1 ));
        
        for (int i = 0; i < n/2; i++) {
            for (int j = 0; j < n/2; j++) {
                (*rMat)(n/2 + i, n/2 + j) = (*c22a)(i, j) + (*c22b)(i, j);
            }
        }
    }
    
    return rMat;
}