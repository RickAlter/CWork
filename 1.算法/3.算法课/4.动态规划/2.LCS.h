/*************************************************************************
	> File Name: LCS.h
	> Author: 
	> Mail: 
	> Created Time: 2020年11月16日 星期一 16时16分26秒
 ************************************************************************/

#ifndef _LCS_H
#define _LCS_H
#include <iostream>
using namespace std;

void LCS(int i, int j, char *x, int **b) {
    cout << "最长公共子序列为:" << endl;
    for (int k = 0; k < i; k++) {
        for (int l = 0; l < j; l++) {
            if (b[k][l] == 1) {
                cout << x[k] << " ";
            }
        }
    }
    cout << endl;
}

#endif
