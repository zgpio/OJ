#include <cstdio>
#include <iostream>
using namespace std;
// 问题描述：
// 有N件物品和一个容量为C的背包。第i件物品的重量是w[i]，价值是v[i]。求解将哪些物品装入背包可使价值总和最大。

pair<int, int> pack01(int N, int C, int w[], int v[])
{
    int dp[N][C + 1];
    // dp[i][c] 表示0~i件物品，容量为c的背包最优解
    // dp[0][c] = 0, ..., 0, v[0], ..., v[0]
    for (int c = 0; c <= C; c++) {
        dp[0][c] = c >= w[0] ? v[0] : 0;
    }

    for (int i = 1; i < N; i++) {
        for (int c = 0; c <= C; c++) {
            if (c >= w[i])
                dp[i][c] = max(dp[i - 1][c - w[i]] + v[i], dp[i - 1][c]);
            else
                dp[i][c] = dp[i - 1][c];
        }
    }
    int w_sum = 0;
    int c = C;
    for (int i = N - 1; i >= 0; i--) {
        if (dp[i][c] == dp[i - 1][c - w[i]] + v[i]) {
            w_sum += w[i];
            c -= w[i];
        }
    }

    return make_pair(w_sum, dp[N - 1][C]);
}

// http://oj.acm.zstu.edu.cn/JudgeOnline/problem.php?id=4034
int main(int argc, char *argv[])
{
#ifdef LOCAL_JUDGE
    freopen("../input/pack01", "rt", stdin);
#endif
    int N, C;
    while (scanf("%d%d", &C, &N) != EOF) {
        int w[N];
        int v[N];
        for (int i = 0; i < N; i++) {
            scanf("%d%d", &w[i], &v[i]);
        }
        auto res = pack01(N, C, w, v);

        cout << res.first << " " << res.second << endl;
    }

    return 0;
}
