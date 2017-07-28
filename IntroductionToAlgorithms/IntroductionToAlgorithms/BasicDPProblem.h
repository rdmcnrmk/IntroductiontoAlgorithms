//
//  BasicDPProblem.h
//  IntroductionToAlgorithms
//
//  Created by Erdem Can Irmak on 7/24/17.
//  Copyright © 2017 Erdem Can Irmak. All rights reserved.
//

#ifndef BasicDPProblem_h
#define BasicDPProblem_h

class BasicDPProblem {
    int *dp;

public:
    
    BasicDPProblem(int n);
    
    int SolveWithNaiveMathod(int n);
    int SolveWithDPMethod(int n);
    
    
};


BasicDPProblem::BasicDPProblem(int n) {
    dp = new int[n+1];
    
    for (int i = 0; i <= n; i++) {
        dp[i] = -1;
    }
    
    cout << SolveWithNaiveMathod(n) << endl;
    cout << SolveWithDPMethod(n) << endl;
}

int BasicDPProblem::SolveWithNaiveMathod(int n) {
    
    if(n < 0) {
        return 0;
    }
    if(n == 0) {
        return 1;
    }
    
    return SolveWithNaiveMathod(n-1) + SolveWithNaiveMathod(n-3) + SolveWithNaiveMathod(n-5);
}

int BasicDPProblem::SolveWithDPMethod(int n) {
    if(n < 0) {
        return 0;
    }
    if(n == 0) {
        return 1;
    }
    if(dp[n] != -1) {
        return dp[n];
    }
    
    dp[n] = SolveWithNaiveMathod(n-1) + SolveWithNaiveMathod(n-3) + SolveWithNaiveMathod(n-5);
    return dp[n];
}

#endif /* BasicDPProblem_h */
