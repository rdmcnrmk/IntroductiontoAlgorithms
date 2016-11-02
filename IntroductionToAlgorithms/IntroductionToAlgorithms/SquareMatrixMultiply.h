//
//  SquareMatrixMultiply.h
//  IntroductionToAlgorithms
//
//  Created by Erdem Can Irmak on 9/28/16.
//  Copyright © 2016 Erdem Can Irmak. All rights reserved.
//

#ifndef SquareMatrixMultiply_h
#define SquareMatrixMultiply_h

#include <stdio.h>
#include "Matrix2D.h"

class SquareMatrixMultiply {
public:
    SquareMatrixMultiply();
    Matrix2D<int> *CreateInput1();
    Matrix2D<int> *Run(Matrix2D<int> *a, Matrix2D<int> *b);
    
};

#endif /* SquareMatrixMultiply_h */
