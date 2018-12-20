#include <string.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

// left/right: left/right index
// 待查元素x
// i/j: 小于x的最大元素位置i, 大于x的最小元素位置j
template <typename T>
int binarySearch(T a[], const T &x, int left, int right, int &i, int &j)
{
    int middle;
    while (left <= right) {
        middle = (left + right) / 2;
        if (x == a[middle]) {
            i = j = middle;
            return 1;
        }
        if (x > a[middle])
            left = middle + 1;
        else
            right = middle - 1;
    }
    i = right;
    j = left;
    return 0;
}

int main()
{
    srand(time(NULL));
    int low = 9, high = 19;
    int rnum = rand() % (high - low + 1) + low;
    int *arr = new int[rnum];
    for (int i = 0; i < rnum; ++i) {
        arr[i] = rand() % (100 - 0 + 1) + 0;
    }
    sort(arr, arr + rnum);

    for (int i = 0; i < rnum; ++i) {
        std::cout << i << ": " << arr[i] << "  ";
    }
    cout << endl;
    int find = 50;
    int i, j;
    binarySearch(arr, find, 0, 9, i, j);
    std::cout << i << " " << j << std::endl;

    return 0;
}
