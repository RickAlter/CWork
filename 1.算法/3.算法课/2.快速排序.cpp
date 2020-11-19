/*************************************************************************
	> File Name: 2.快速排序.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年11月15日 星期日 09时09分45秒
 ************************************************************************/

#include<iostream>
using namespace std;

void Quick_sort(int *arr, int l, int r) {
    if (l < r) {
        int i = l;
        int j = r;
        int k = arr[l];
        while (i < j) {
            while (i < j && arr[j] >= k) {
                j--;
            }
            if (i < j) {
                arr[i++] = arr[j];
            }
            while (i < j && arr[i] < k) {
                i++;
            }
            if (i < j) {
                arr[j--] = arr[i];
            }
        }
        arr[i] = k;
        Quick_sort(arr, l, i - 1);
        Quick_sort(arr, i + 1, r);
    }
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
    int num[n];
    int l, r;
    cin >> l >> r;
    Random(num, n, l, r);
    Quick_sort(num, 0, n - 1);
    PRINTF(num, n);
    return 0;
}
