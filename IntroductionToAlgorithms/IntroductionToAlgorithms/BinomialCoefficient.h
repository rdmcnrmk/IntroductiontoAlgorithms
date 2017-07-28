//
//  BinomialCoefficient.h
//  IntroductionToAlgorithms
//
//  Created by Erdem Can Irmak on 7/27/17.
//  Copyright © 2017 Erdem Can Irmak. All rights reserved.
//

#ifndef BinomialCoefficient_h
#define BinomialCoefficient_h

using namespace std;

class BinomialCoefficient {
public:
    BinomialCoefficient();
    int ApplyBCNaive(int n, int k);
    int ApplyBCOverlappingS(int n, int k);
};


BinomialCoefficient::BinomialCoefficient() {
    
}


int BinomialCoefficient::ApplyBCNaive(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    }
    
    return ApplyBCNaive(n-1, k-1) + ApplyBCNaive(n-1, k);
}

int BinomialCoefficient::ApplyBCOverlappingS(int n, int k) {
    int bc[n+1][k+1];
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= min(i, k); j++) {
            if(j == 0 || j == i) {
                bc[i][j] = 1;
            }
            else {
                bc[i][j] = bc[i-1][j-1] + bc[i-1][j];
            }
        }
    }
    
    return bc[n][k];
}



#endif /* BinomialCoefficient_h */
