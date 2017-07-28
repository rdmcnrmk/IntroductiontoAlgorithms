//
//  JobSequencingProblem.h
//  IntroductionToAlgorithms
//
//  Created by Erdem Can Irmak on 7/20/17.
//  Copyright © 2017 Erdem Can Irmak. All rights reserved.
//

#ifndef JobSequencingProblem_h
#define JobSequencingProblem_h

using namespace std;

struct Job {
    char name;
    int deadline;
    int profit;
};


bool CompareJobs(Job a, Job b) {
    return (a.profit > b.profit);
}

class JobSequencingProblem {
    
    Job* jobs;
    int size;
    
public:
    JobSequencingProblem();
    void Run();
};

JobSequencingProblem::JobSequencingProblem() {
    Job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, {'d', 1, 25}, {'e', 3, 15}};
    this->size = sizeof(arr)/sizeof(arr[0]);
    sort(arr, arr+size, CompareJobs);
    this->jobs = arr;
    
    int results[size];
    bool slot[size];
    
    for (int i = 0; i < size; i++) {
        slot[i] = false;
    }
    
    for (int i = 0; i < size; i++) {
        
        for(int j = min(size, arr[i].deadline)-1; j>= 0; j--) {
            if(slot[j] == false) {
                results[j] = i;
                slot[j] = true;
                break;
            }
        }
    }
    
    for (int i = 0; i < size; i++) {
        if(slot[i])
            cout << jobs[results[i]].name << endl;
    }
}

void JobSequencingProblem::Run() {
    
}



#endif /* JobSequencingProblem_h */
