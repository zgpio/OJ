#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
template <class T>
T min(int n, T *x)
{
    T val = x[0];
    for (int i = 1; i < n; i++)
        if (x[i] < val) {
            val = x[i];
        }
    return val;
}

template <class T>
T max(int n, T *x)
{
    T val = x[0];
    for (int i = 1; i < n; i++)
        if (x[i] > val) {
            val = x[i];
        }
    return val;
}

double maxgap(int n, double *x)
{
    double minx = min(n, x), maxx = max(n, x);
    // 用n-2个等间距点分割区间[minx, maxx],
    // 产生n-1个桶, 每个桶i中用high[i]和low[i]
    // 分别存储分配给桶i的数中的最大数和最小数
    int *count = new int[n - 1];
    double *low = new double[n - 1];
    double *high = new double[n - 1];
    // 桶初始化
    for (int i = 0; i < n - 1; i++) {
        count[i] = 0;
        low[i] = maxx;
        high[i] = minx;
    }
    // 将n个数置于n-1个桶中
    for (int i = 0; i < n; i++) {
        int bucket = int((n - 1) * (x[i] - minx) / (maxx - minx));
        if (bucket == n - 1) bucket--;
        count[bucket]++;
        if (x[i] < low[bucket]) low[bucket] = x[i];
        if (x[i] > high[bucket]) high[bucket] = x[i];
    }
    // 此时, 除了maxx和minx外的n-2个数被置于n-1个桶中.
    // 由鸽舍原理即知, 至少有一个桶是空的.
    // 这意味着最大间隙不会出现在同一个桶中的两个数之间.
    // 对每一个桶做一次线性扫描即可找出最大间隙.
    double res = 0, left = high[0];
    for (int i = 1; i < n - 1; i++) {
        if (count[i]) {
            double thisgap = low[i] - left;
            if (thisgap > res) res = thisgap;
            left = high[i];
        }
    }
    return res;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input1_5", "rt", stdin);
#endif
    int n;
    double *a = new double[n];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &a[i]);
    }
    printf("%lf\n", maxgap(n, a));

    return 0;
}
