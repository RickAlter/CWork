/*************************************************************************
    > File Name: 线性选择算法.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2020年11月14日 星期六 19时30分00秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

void Swap(int &a, int &b) {
    a ^= b;
    b ^= a;
    a ^= b;
}

int Partition(int a[], int p, int r) {
    int i = p - 1;
    int pivot = a[r];
    for (int j = p; j < r; j++) {
        if (a[j] <= pivot) {
            i++;
            Swap(a[i], a[j]);
        }
    }
    Swap(a[i + 1], a[r]);
    return i + 1; 
}

void SelectSort(int a[], int p, int r) {
    for (int i = p; i < r; i++) {
        for (int j = i + 1; j <= r; j++) {
            if (a[i] > a[j]) 
            Swap(a[i], a[j]);
        }
    }
}

int Select(int a[], int p, int r, int k) {
    if ((r - p) < 7) {
        SelectSort(a, p , r);
        return a[p + k - 1];
    }
    for (int i = 0; i < (r - p) / 5; i++) {
        int j = p + 5 * i;
        SelectSort(a, j, j + 4);
        Swap(a[p + i], a[j + 2]);
    }
    int x = Select(a, p, p + (r - p) / 5 - 1, (r - p) / 10);
    int index_x = p + (r - p) / 10;
    Swap(a[index_x], a[r]);
    int key1, key2;
    key1 = Partition(a, p, r);
    key2 = key1 - p + 1;
    if (k < key2) {
        return Select(a, p, key1 - 1, k);
    }
    if (k > key2) {
        return Select(a, key1 + 1, r, k - key2);
    }
    return a[key1];
}

void Random(int *arr, int n, int l, int r) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (r - l + 1) + l;
    }
}

void PRINTF(int *arr, int n) {
    for (int i = 0; i < n; i++) {

        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    int l, r;
    cin >> l >> r;
    Random(a, n, l, r);
    PRINTF(a, n);
    for (int j = 1; j <= n; j++) {
        int tmp;
        tmp = Select(a, 0, n - 1, j);
        printf("The %d is %d", j, tmp);
        cout << endl;
    }
    return 0;
}
