/*************************************************************************
	> File Name: 5贪心算法.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年11月16日 星期一 20时49分40秒
 ************************************************************************/

#include<iostream>
#include <algorithm>
using namespace std;

struct ActionInfo {
    int index;
    int startTime;
    int endTime;
};

bool cmp(const ActionInfo &a, ActionInfo &b) {
    if (a.endTime <= b.endTime) {
        return true;
    }
    return false;
}

int main() {
    int actionGroups = 0;
    cin >> actionGroups;
    ActionInfo *act = new ActionInfo[actionGroups];
    for (int i = 0; i < actionGroups; i++) {
        cin >> act[i].index >> act[i].startTime >> act[i].endTime;
    }

    sort(act, act + actionGroups, cmp);

    int currentAction = 0, count = 0;
    int notConflictActionsIndex[100];
    notConflictActionsIndex[count] = act[0].index;
    for (int j = 1; j < actionGroups; j++) {
        if (act[j].startTime >= act[currentAction].endTime) {
            currentAction = j;
            notConflictActionsIndex[++count] = act[j].index;
        }
    }
    for (int k = 0; k <= count; k++) {
        cout << notConflictActionsIndex[k] << ' ';
    }
    cout << endl;
    delete[] act;
    system("pause");
    return 0;
}
