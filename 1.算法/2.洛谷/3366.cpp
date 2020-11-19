/*************************************************************************
    > File Name: 3366.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2020年11月12日 星期四 20时42分27秒
 ************************************************************************/
#include <iostream>
#include <algorithm>
using namespace std;

struct edge {
    int s, e, v;
};

bool cmp(const edge &a, const edge &b) {
    return a.v < b.v;
}

edge edg[200005];
int n, m, ans, my_union[5005], already = 1;

int find_root(int x) {
    if (my_union[x] == x) {
        return x;
    }
    return my_union[x] = find_root(my_union[x]);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> edg[i].s >> edg[i].e >> edg[i].v;
    }
    for (int i = 1; i <= n; i++) {
        my_union[i] = i;
    }
    sort(edg, edg + m, cmp);
    for (int i = 0; i <= m; i++) {
        int sr = find_root(edg[i].s), er = find_root(edg[i].e);
        if (sr != er) {
            already++;
            ans += edg[i].v;
            my_union[sr] = er;
            if (already == n) {
                break;
            }
        }
    }
    if (already == n) {
        cout << ans << endl;
    } else {
        cout << "orz" << endl;
    }
    return 0;
}

