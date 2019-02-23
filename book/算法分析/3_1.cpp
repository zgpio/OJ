#include <stdio.h>
#include <cassert>
#include <climits>
#include <iostream>
using namespace std;
/*
 * 最长单调递增子序列
 * 最长不下降子序列
 * Longest Increasing Subsequence
 */

int LISdyna(int a[], int n)
{
    int* dp = new int[n];
    int maxa = INT_MIN;
    // dp[i] 表示a[i]结尾的LIS
    for (int i = 0; i < n; i++) dp[i] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++)
            if (a[j] <= a[i] && dp[i] < dp[j] + 1) dp[i] = dp[j] + 1;
        if (dp[i] > maxa) maxa = dp[i];
    }
    return maxa;
}

int main()
{
    int a[] = {3, 1, 2, 5, 4, 3, 4, 5, 6};
    std::cout << "len: " << sizeof(a) / sizeof(a[0]) << std::endl;
    int res = LISdyna(a, sizeof(a) / sizeof(a[0]));
    std::cout << res << std::endl;
    assert(res == 6);
    return 0;
}
