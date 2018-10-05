#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

// left/right: left/right index
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
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int find = 9;
    int i, j;
    binarySearch(a, find, 0, 9, i, j);
    std::cout << i << j << std::endl;

    return 0;
}
