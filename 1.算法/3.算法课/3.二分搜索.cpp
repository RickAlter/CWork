/*************************************************************************
	> File Name: 3.二分搜索.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年11月14日 星期六 21时05分53秒
 ************************************************************************/
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

int binary_search(int n, int *arr, int x) {
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (x == arr[mid]) return mid;
        else if (x < arr[mid]) r = mid - 1;
        else l = mid +1;
    }
    return -1;
}

void Random(int *a, int n, int l, int r) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        a[i] = rand() % (r - l + 1) + l;
    }
}

void PRINTF(int *a, int n) {
    for (int i = 0; i < n; i++) {

        cout << a[i] << " ";

    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    int num[n];
    int l, r;
    cin >> l >> r;
    Random(num, n, l, r);
    sort (num, num + n);
    PRINTF(num, n);
    int x;
    cin >> x;
    int p = binary_search(n, num, x);
    cout << p << endl;
    return 0;
}
