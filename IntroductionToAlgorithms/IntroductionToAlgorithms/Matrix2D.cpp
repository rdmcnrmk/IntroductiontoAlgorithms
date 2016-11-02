//
//  Matrix2D.cpp
//  IntroductionToAlgorithms
//
//  Created by Erdem Can Irmak on 9/28/16.
//  Copyright © 2016 Erdem Can Irmak. All rights reserved.
//

#include "Matrix2D.h"

template<typename T>
Matrix2D<T>::Matrix2D (unsigned int dimx, unsigned int dimy): dimx_ (dimx), dimy_ (dimy) {
    inner_.resize (dimx_ * dimy_);
}

template<typename T>
T& Matrix2D<T>::operator()(unsigned int x, unsigned int y)
{
    if (x >= dimx_ || y>= dimy_)
     throw 0; // ouch
    return inner_[dimx_*y + x];
}

template<typename T>
void Matrix2D<T>::Print() {
    for (int i = 0; i < dimx_; i++) {
        for (int j =0; j < dimy_; j++) {
            std::cout << inner_[dimx_*i+j] << " ";
        }
        std::cout << std::endl;
    }
}

template<typename T>
Matrix2D<T> *Matrix2D<T>::MatrixPartition(unsigned int minX, unsigned int maxX, unsigned int minY, unsigned int maxY) {
    Matrix2D<T> *rMat = new Matrix2D<T>(maxX - minX + 1, maxY - minY + 1);
    
    for (int i = 0; i < (maxX - minX + 1); i++) {
        for (int j = 0; j < (maxY - minY + 1); j++) {
            (*rMat)(i, j) = (*this)(minX + i, minY + j);
        }
    }
    return rMat;
}

template<typename T>
int Matrix2D<T>::GetRowCount() {
    return dimx_;
}

template<typename T>
int Matrix2D<T>::GetColumnCount() {
    return dimy_;
}

template<typename T>
Matrix2D<T> *Matrix2D<T>::Sum(Matrix2D<T> *a, Matrix2D<T> *b) {
    int n = a->GetColumnCount();
    Matrix2D<T> *c = new Matrix2D<T>(n,n);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            (*c)(i,j) = (*a)(i,j) + (*b)(i,j);
        }
    }
    return  c;
}

template<typename T>
Matrix2D<T> *Matrix2D<T>::Subtract(Matrix2D<T> *a, Matrix2D<T> *b) {
    int n = a->GetColumnCount();
    Matrix2D<T> *c = new Matrix2D<T>(n,n);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            (*c)(i,j) = (*a)(i,j) - (*b)(i,j);
        }
    }
    return  c;
}

template class Matrix2D<int>;
