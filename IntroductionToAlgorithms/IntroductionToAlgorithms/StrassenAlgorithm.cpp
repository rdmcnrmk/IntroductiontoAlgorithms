//
//  StrassenAlgorithm.cpp
//  IntroductionToAlgorithms
//
//  Created by Erdem Can Irmak on 10/4/16.
//  Copyright © 2016 Erdem Can Irmak. All rights reserved.
//

#include "StrassenAlgorithm.h"

StrassenAlgorithm::StrassenAlgorithm() {
    
}

Matrix2D<int> *StrassenAlgorithm::CreateInput1() {
    Matrix2D<int> *rMat = new Matrix2D<int>(4, 4);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            (*rMat)(i, j) = rand() % 4;
        }
    }
    
    return rMat;
}

Matrix2D<int> *StrassenAlgorithm::Run(Matrix2D<int> *a, Matrix2D<int> *b) {
    
    int n = a->GetRowCount();
    Matrix2D<int> *rMat;
    int newN = n/2;
    
    if (n == 1) {
        rMat = new Matrix2D<int>(1, 1);
        (*rMat)(0, 0) = (*a)(0, 0) * (*b)(0, 0);
    }
    else {
        rMat = new Matrix2D<int>(n, n);
        Matrix2D<int> *a11 = a->MatrixPartition(0, newN - 1, 0, newN - 1);
        Matrix2D<int> *a12 = a->MatrixPartition(0, newN - 1, newN, n - 1);
        Matrix2D<int> *a21 = a->MatrixPartition(newN, n - 1, 0, newN - 1);
        Matrix2D<int> *a22 = a->MatrixPartition(newN, n - 1, newN, n - 1);
        Matrix2D<int> *b11 = b->MatrixPartition(0, newN - 1, 0, newN - 1);
        Matrix2D<int> *b12 = b->MatrixPartition(0, newN - 1, newN, n - 1);
        Matrix2D<int> *b21 = b->MatrixPartition(newN, n - 1, 0, newN - 1);
        Matrix2D<int> *b22 = b->MatrixPartition(newN, n - 1, newN, n - 1);
        
        Matrix2D<int> *aResult = a->Sum(a11, a22);
        Matrix2D<int> *bResult = a->Sum(b11, b22);
        Matrix2D<int> *p1 = Run(aResult, bResult);
        
        aResult = a->Sum(a21, a22);
        Matrix2D<int> *p2 = Run(aResult, b11);
        
        bResult = a->Subtract(b12, b22);
        Matrix2D<int> *p3 = Run(a11, bResult);
        
        bResult = a->Subtract(b21, b11);
        Matrix2D<int> *p4 = Run(a22, bResult);
        
        aResult = a->Sum(a11, a12);
        Matrix2D<int> *p5 = Run(aResult, b22);
        
        aResult = a->Subtract(a21, a11);
        bResult = a->Sum(b11, b12);
        Matrix2D<int> *p6 = Run(aResult, bResult);
        
        aResult = a->Subtract(a12, a22);
        bResult = a->Sum(b21, b22);
        Matrix2D<int> *p7 = Run(aResult, bResult);
        
        
        Matrix2D<int> *c12 = a->Sum(p3, p5);
        Matrix2D<int> *c21 = a->Sum(p2, p4);
        
        aResult = a->Sum(p1, p4);
        bResult = a->Sum(aResult, p7);
        Matrix2D<int> *c11 = a->Subtract(bResult, p5);
        
        aResult = a->Sum(p1, p3);
        bResult = a->Sum(aResult, p6);
        Matrix2D<int> *c22 = a->Subtract(bResult, p2);
        
        for (int i = 0; i < n/2; i++) {
            for (int j = 0; j < n/2; j++) {
                (*rMat)(i, j) = (*c11)(i, j);
            }
        }
        for (int i = 0; i < n/2; i++) {
            for (int j = 0; j < n/2; j++) {
                (*rMat)(i, n/2 + j) = (*c12)(i, j);
            }
        }
        for (int i = 0; i < n/2; i++) {
            for (int j = 0; j < n/2; j++) {
                (*rMat)(n/2 + i, j) = (*c21)(i, j);
            }
        }
        for (int i = 0; i < n/2; i++) {
            for (int j = 0; j < n/2; j++) {
                (*rMat)(n/2 + i, n/2 + j) = (*c22)(i, j);
            }
        }
        
    }
    
    return rMat;
}