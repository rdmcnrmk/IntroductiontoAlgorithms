//
//  EgyptianFraction.h
//  IntroductionToAlgorithms
//
//  Created by Erdem Can Irmak on 7/20/17.
//  Copyright © 2017 Erdem Can Irmak. All rights reserved.
//

#ifndef EgyptianFraction_h
#define EgyptianFraction_h

using namespace std;

class EgyptianFraction {
    int nr;
    int dr;

    void RunHelper(int nr, int dr);
public:
    EgyptianFraction(int nr, int dr);
    void Run();
};

EgyptianFraction::EgyptianFraction(int nr, int dr) {
    this->nr = nr;
    this->dr = dr;
}

void EgyptianFraction::Run() {
    int nr = 6, dr = 14;
    cout << "Egyptian Fraction Representation of "
    << nr << "/" << dr << " is\n ";
    RunHelper(nr, dr);
    
}

void EgyptianFraction::RunHelper(int nr, int dr) {
    
    if(nr == 0 || dr == 0) {
        return;
    }
    
    if(dr % nr == 0) {
        cout << "1/" << dr / nr << endl;
        return;
    }
    
    if(nr % dr == 0) {
        cout << nr / dr << endl;
        return;
    }
    
    if(nr > dr) {
        cout << nr / dr << " + ";
        RunHelper(nr%dr, dr);
        return;
    }
    
    int n = dr / nr + 1;
    cout << "1/" << n << " + ";
    RunHelper(nr * n - dr, dr * n);
}


#endif /* EgyptianFraction_h */
