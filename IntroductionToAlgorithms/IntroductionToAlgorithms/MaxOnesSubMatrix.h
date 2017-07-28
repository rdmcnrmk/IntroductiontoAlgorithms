//
//  MaxOnesSubMatrix.h
//  IntroductionToAlgorithms
//
//  Created by Erdem Can Irmak on 7/28/17.
//  Copyright © 2017 Erdem Can Irmak. All rights reserved.
//

#ifndef MaxOnesSubMatrix_h
#define MaxOnesSubMatrix_h

#include <vector>

using namespace std;

class MaxOnesSubMatrix{
    
public:
    MaxOnesSubMatrix();
    void ApplyMSM(vector<vector<int>> m);
};

MaxOnesSubMatrix::MaxOnesSubMatrix() {
    vector<vector<int>> M =  {{0, 1, 1, 0, 1},
        {1, 1, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0}};
    
    ApplyMSM(M);
}

void MaxOnesSubMatrix::ApplyMSM(vector<vector<int>> m) {
    
    int r = (int)m.size();
    int c = (int)m[0].size();
    
    int resultM[r][c];
    
    for (int i = 0; i< r; i++) {
        for (int j = 0; j < c; j++) {
            resultM[i][j] = 0;
        }
    }
    
    for (int i = 0; i < r; i++) {
        resultM[i][0] = m[i][0];
    }
    
    for (int i = 1; i < c; i++) {
        resultM[0][c] = m[0][c];
    }
    
    for (int i = 1; i< r; i++) {
        for (int j = 1; j < c; j++) {
            
            if(m[i][j] == 0) {
                resultM[i][j] = 0;
            }
            else {
                resultM[i][j] = min(min(resultM[i-1][j], resultM[i][j-1]), resultM[i-1][j-1]) + 1;
            }
            
        }
    }
    
    int maxS = 0;
    
    for (int i = 1; i< r; i++) {
        for (int j = 1; j < c; j++) {
            if (maxS < resultM[i][j]) {
                maxS = resultM[i][j];
            }
        }
    }
    
    cout << maxS << endl;
    
    
}

#endif /* MaxOnesSubMatrix_h */
