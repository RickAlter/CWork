/*************************************************************************
	> File Name: 4.动态规划.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年11月16日 星期一 15时52分18秒
 ************************************************************************/

#include<iostream>
#include "3.LCSLength.h"
using namespace std;
#define ans 7
int main() {
    int c[ans][ans], b[ans][ans];
    char x[ans], y[ans];
    int *p[ans], *q[ans];
    cout << "请输入第一个数组:" << endl;
    for (int k = 0; k < 7; k++) {
        cin >> x[k];
        p[k] = c[k];
        q[k] = b[k];
    }
    cout << "请输入第二个数组:" << endl;
    for (int l = 0; l < ans; l++) {
        cin >> y[l];
    }
    LCSLength(ans, ans, x, y, p, q);
    return 0;
}
