//
//  LargestSubArray.h
//  IntroductionToAlgorithms
//
//  Created by Erdem Can Irmak on 7/28/17.
//  Copyright © 2017 Erdem Can Irmak. All rights reserved.
//

#ifndef LargestSubArray_h
#define LargestSubArray_h

#include "vector"

using namespace std;

class LargestSubArray {


public:
    LargestSubArray();
    int ApplyLS(vector<int> a);
};

LargestSubArray::LargestSubArray() {
    vector<int> a = {-2, -3, 4, -1, -2, 1, 5, -3};
    cout << ApplyLS(a) << endl;
}

int LargestSubArray::ApplyLS(vector<int> a) {
    int maxSoFar = INT_MIN;
    int maxEndingHere = 0;
    
    for (int i = 0; i < a.size(); i++) {
        maxEndingHere += a[i];
        
        if(maxEndingHere < 0) {
            maxEndingHere = 0;
        }
        else if(maxEndingHere > maxSoFar) {
            maxSoFar = maxEndingHere;
        }
        
    }
    
    return maxSoFar;
}


#endif /* LargestSubArray_h */
