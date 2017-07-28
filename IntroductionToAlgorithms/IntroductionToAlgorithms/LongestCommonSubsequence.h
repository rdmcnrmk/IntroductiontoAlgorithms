//
//  LongestCommonSubsequence.h
//  IntroductionToAlgorithms
//
//  Created by Erdem Can Irmak on 7/27/17.
//  Copyright © 2017 Erdem Can Irmak. All rights reserved.
//

#ifndef LongestCommonSubsequence_h
#define LongestCommonSubsequence_h

class LongestCommonSubsequence {
public:
    
    LongestCommonSubsequence();
    int ApplyLCS(char *c1, char *c2, int m, int n);
    int ApplyLCOverlappingS(char *c1, char *c2, int m, int n);
};

LongestCommonSubsequence::LongestCommonSubsequence() {
    
}

int LongestCommonSubsequence::ApplyLCS(char *c1, char *c2, int m, int n) {
    
    if(m  == 0|| n == 0) {
        return 0;
    }
    
    if(c1[m-1] == c2[n-1]) {
        return 1 + ApplyLCS(c1, c2, m-1, n-1);
    }
    
    return max(ApplyLCS(c1, c2, m-1, n), ApplyLCS(c1, c2, m, n-1));
}

int LongestCommonSubsequence::ApplyLCOverlappingS(char *c1, char *c2, int m, int n) {
    
    int lcs[m+1][n+1];
    
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if(i  == 0|| j == 0) {
                lcs[i][j] = 0;
            }
            else if(c1[i-1] == c2[j-1]) {
                lcs[i][j] =  1 + lcs[i-1][j-1];
            }
            else {
                lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
            }
        }
    }
    
    return lcs[m][n];
}


#endif /* LongestCommonSubsequence_h */
