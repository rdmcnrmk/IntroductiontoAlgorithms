//
//  UglyNumbers.h
//  IntroductionToAlgorithms
//
//  Created by Erdem Can Irmak on 7/28/17.
//  Copyright © 2017 Erdem Can Irmak. All rights reserved.
//

#ifndef UglyNumbers_h
#define UglyNumbers_h

using namespace std;

class UglyNumbers {
    bool IsUgly(int n);
    int MaxDivide(int a, int b);
public:
    UglyNumbers();
    int ApplyUNNaive(int n);
};

int UglyNumbers::MaxDivide(int a, int b) {
    while(a%b == 0) {
        a = a/b;
    }
    return a;
}

UglyNumbers::UglyNumbers() {
    cout << ApplyUNNaive(150) << endl;
}

bool UglyNumbers::IsUgly(int n) {
    
    n = MaxDivide(n, 2);
    n = MaxDivide(n, 3);
    n = MaxDivide(n, 5);
    
    return (n == 1)? true : false;
}

int UglyNumbers::ApplyUNNaive(int n) {
    
    int counter = 0;
    int i = 0;
    
    while(counter < n) {
        i++;

        if(IsUgly(i)) {
            counter++;
        }
    }
    
    return i;
}

#endif /* UglyNumbers_h */
