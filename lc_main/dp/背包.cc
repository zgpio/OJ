// 动态规划-完全背包问题, “完全”相较于“01”而言

#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

// *********************************************************
//  函数功能: 动态规划求解最大价值和分配方案
//  函数参数: v-价值, w-重量, n-物品种类, C-背包容量
//  返 回 值: 最大价值
// *********************************************************
//      0   1    ...    C
//     ──────────────────> 递推方向
//    ┌───┬───┬───┬───┬───┐
//  0 │   │   │   │   │   │
//    ├───┼───┼───┼───┼───┤
//  1 │   │   │   │   │   │
//    ├───┼───┼───┼───┼───┤
//  . │   │   │   │   │   │
//  . ├───┼───┼───┼───┼───┤
//  . │   │   │   │   │   │
//    ├───┼───┼───┼───┼───┤
// N-1│   │   │   │   │   │
//    └───┴───┴───┴───┴───┘
int KnapSack(const int v[], const int w[], const int N, const int C)
{
    int f[N][C + 1];  // f[i][j] 表示[0,i]件物品，容量为j的子问题最优解

    for (int j = 0; j <= C; j++)
        f[0][j] = j / w[0] * v[0];

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < w[i]; j++)
            f[i][j] = f[i - 1][j];  // 对于求解最优值是必要的, 删除后结果错误
        for (int j = w[i]; j <= C; j++) {
            f[i][j] = max(f[i - 1][j], f[i][j - w[i]] + v[i]);
        }
    }

    int c = C;
    int x[N];  // 分配状态
    for (int i = N - 1; i >= 0; i--) {
        x[i] = 0;
        for (int j = 0; j <= C / w[i]; j++) {
            if (f[i][c] == f[i - 1][c - j * w[i]] + j * v[i]) {
                x[i] = j;
                c -= j * w[i];
                break;
            }
        }
    }

    cout << "二维数组规划-最大价值为: " << f[N - 1][C] << endl;
    cout << "分配状态为: ";
    for (int i = 0; i < N; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
    return f[N - 1][C];
}

// **********************************************************
//  函数功能: 动态规划求解最大价值
//  函数参数: v-价值, w-重量, n-物品种类, C-背包容量
//  返 回 值: 最大价值
// **********************************************************
int KnapSack2(const int v[], const int w[], const int n, const int C)
{
    int dp[C + 1];  // 存储最优解
    for (int j = 0; j <= C; j++) {
        dp[j] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = w[i]; j <= C; j++) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << "一维数组规划-最大价值为: " << dp[C] << endl;
    return dp[C];
}

int main()
{
    {
        const int n = 5;  // 物体个数
        int v[n] = {3, 4, 5, 3, 6};
        int w[n] = {4, 5, 3, 2, 5};
        int C = 10;  // 背包最大容量

        int pred1 = KnapSack(v, w, n, C);   // 经典
        int pred2 = KnapSack2(v, w, n, C);  // 优化之后
        assert(pred1 == pred2);
        assert(pred1 == 16);
    }
    {
        const int n = 4;
        int v[n] = {1, 3, 5, 9};
        int w[n] = {2, 3, 4, 7};
        int C = 10;

        int pred1 = KnapSack(v, w, n, C);
        int pred2 = KnapSack2(v, w, n, C);
        assert(pred1 == pred2);
        assert(pred1 == 12);
    }
    return 0;
}
