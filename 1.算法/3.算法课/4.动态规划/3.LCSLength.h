/*************************************************************************
	> File Name: LCSLength.h
	> Author: 
	> Mail: 
	> Created Time: 2020年11月16日 星期一 16时00分51秒
 ************************************************************************/

#ifndef _LCSLENGTH_H
#define _LCSLENGTH_H
#include <iostream>
#include "2.LCS.h"
using namespace std;
void LCSLength(int m, int n, char *x, char *y, int **c, int **b) {
    int *z[7];
    for (int i = 0; i < m; i++) {
        c[i][0] = 0;
        b[i][0] = 0;
    }
    for (int i = 0; i < n; i++) {
        c[0][i] = 0;
        b[0][i] = 0;
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (x[i] == y[j]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 1;
            } else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                b[i][j] = 2;
            } else {
                c[i][j] = c[i][j - 1];
                b[i][j] = 3;
            }
        }
        cout << endl;
    }
    for (int k = 0; k < 7; k++) {
        z[k] = b[k];
    }
    LCS(7, 7, x, z);
}
#endif
