#include <stdio.h>
#include <iostream>
using namespace std;
/*
 * 最长单调递增子序列
 * Longest Increasing Subsequence
 */
int maxL(int a[], int n)
{
    int max = 0;
    for (int i = 0; i < n; i++)
        if (a[i] > max) max = a[i];
    return max;
}

int LISdyna(int a[], int n)
{
    int* dp = new int[n];
    for (int i = 0; i < n; i++) dp[i] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++)
            if (a[j] <= a[i] && dp[i] < dp[j] + 1) dp[i] = dp[j] + 1;
    }
    return maxL(dp, n);
}

int main()
{
    int a[] = {3, 1, 2, 5, 4, 3, 4, 5, 6};
    std::cout << "len: " << sizeof(a) / sizeof(a[0]) << std::endl;
    std::cout << LISdyna(a, sizeof(a) / sizeof(a[0])) << std::endl;
    return 0;
}
