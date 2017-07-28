//
//  Fibonacci.h
//  IntroductionToAlgorithms
//
//  Created by Erdem Can Irmak on 7/24/17.
//  Copyright © 2017 Erdem Can Irmak. All rights reserved.
//

#ifndef Fibonacci_h
#define Fibonacci_h


class Fibonacci {
    int *lookUp;
public:
    Fibonacci(int n);
    int FibonacciWithNaiveApproach(int n);
    int FibonacciWithMemoization(int n);
    int FibonacciWithTabulation(int n);
    int FibonacciSpaceOptimized(int n);
};

Fibonacci::Fibonacci(int n) {
    lookUp = new int[n+1];
    
    for (int i = 0; i <=n; i++) {
        lookUp[i] = -1;
    }
}

int Fibonacci::FibonacciWithNaiveApproach(int n) {
    if (n <= 1) {
        return n;
    }
    return FibonacciWithNaiveApproach(n-1) + FibonacciWithNaiveApproach(n-2);
}

int Fibonacci::FibonacciWithMemoization(int n) {
    if (n <= 1) {
        return n;
    }
    
    if(lookUp[n] != -1) {
        return lookUp[n];
    }
    lookUp[n] = FibonacciWithNaiveApproach(n-1) + FibonacciWithNaiveApproach(n-2);
    
    return lookUp[n];
}

int Fibonacci::FibonacciWithTabulation(int n) {
    int f[n+1];
    f[0] = 0;
    f[1] = 1;
    
    for (int i = 2; i <=n; i++) {
        f[i] = f[i-1] + f[i-2];
    }
    
    return f[n];
}

int Fibonacci::FibonacciSpaceOptimized(int n) {
    int a = 0;
    int b = 1;
    int c = 0;
    
    if(n <= 1) {
        return n;
    }
    
    for (int i = 2; i <=n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    
    return c;
    
}

#endif /* Fibonacci_h */
