//
//  StrassenAlgorithm.h
//  IntroductionToAlgorithms
//
//  Created by Erdem Can Irmak on 10/4/16.
//  Copyright © 2016 Erdem Can Irmak. All rights reserved.
//

#ifndef StrassenAlgorithm_h
#define StrassenAlgorithm_h

#include <stdio.h>
#include "Matrix2D.h"

class StrassenAlgorithm {
public:
    StrassenAlgorithm();
    Matrix2D<int> *CreateInput1();
    Matrix2D<int> *Run(Matrix2D<int> *a, Matrix2D<int> *b);
};

#endif /* StrassenAlgorithm_h */
