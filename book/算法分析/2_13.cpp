#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

template <typename T>
void mergesort(T *a, int left, int right)
{
    if (left < right) {
        int j = (int)sqrt(right - left + 1);
        if (j > 1) {
            for (int i = 0; i < j; i++)
                mergesort(a, left + i * j, left + (i + 1) * j - 1);
            mergesort(a, left + j * j, right);
        }
        mergeall(a, left, right);
    }
}

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    mergesort(a, 0, 9);

    return 0;
}
