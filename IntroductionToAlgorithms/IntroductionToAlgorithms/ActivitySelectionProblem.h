//
//  ActivitySelectionProblem.h
//  IntroductionToAlgorithms
//
//  Created by Erdem Can Irmak on 7/20/17.
//  Copyright © 2017 Erdem Can Irmak. All rights reserved.
//

#ifndef ActivitySelectionProblem_h
#define ActivitySelectionProblem_h

using namespace std;


struct Activity {
    int start;
    int finish;
};

bool ActivityCompare(Activity s1, Activity s2)
{
    return (s1.finish < s2.finish);
}

class ActivitySelectionProblem {
    int size;
    Activity* activities;
    
public:
    ActivitySelectionProblem(Activity activities[], int size);
    void Run();
};

ActivitySelectionProblem::ActivitySelectionProblem(Activity activities[], int size)
{
    this->activities = activities;
    this->size = size;
}



void ActivitySelectionProblem::Run() {
    
    sort(activities, activities+size, ActivityCompare);
    
    int activityIndex = 0;
    
    cout << "activity: " << activities[0].start << " " << activities[0].finish << endl;
    
    for (int i = 0; i < size; i++) {
        if(activities[i].start >= activities[activityIndex].finish) {
            cout << "activity: " << activities[i].start << " " << activities[i].finish << endl;
            activityIndex = i;
        }
    }
}

#endif /* ActivitySelectionProblem_h */
