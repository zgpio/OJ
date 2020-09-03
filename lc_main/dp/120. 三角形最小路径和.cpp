#include <bits/stdc++.h>
using namespace std;

// 给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。
class Solution
{
   public:
    // 一维dp数组
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int l = triangle.size();
        int dp[l];  // dp[i] 表示
        dp[0] = triangle[0][0];
        for (int i = 1; i < l; ++i) {  // 1 -> l-1 层
            // (i,i)是第i层最后一个数, 只能通过i-1层的最后一个数到达
            dp[i] = dp[i - 1] + triangle[i][i];
            for (int k = i - 1; k > 0; --k) {
                dp[k] = min(dp[k - 1], dp[k]) + triangle[i][k];
            }
            // (i,0)是第i层第一个数, 只能通过i-1层的第一个数到达
            dp[0] = dp[0] + triangle[i][0];
        }
        int ret = numeric_limits<int>::max();
        for (int i = 0; i < l; ++i) {
            ret = min(dp[i], ret);
        }
        return ret;
    }
    // 二维dp数组
    int minimumTotal2(vector<vector<int>> &triangle)
    {
        const int n = triangle.size();
        int dp[n + 1][n + 1];
        for (int j = 0; j <= n; j++)  // 第n行(0-based)有n+1个数, 用来作为边界
            dp[n][j] = 0;
        for (int i = n - 1; i >= 0; i--)  // 自底向上求解
            for (int j = 0; j <= i; j++)  // 第i行有i+1个数
                dp[i][j] = min(dp[i + 1][j] + triangle[i][j], dp[i + 1][j + 1] + triangle[i][j]);

        return dp[0][0];
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> t1 = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    assert(sol.minimumTotal(t1) == 11);
    vector<vector<int>> t2 = {{-1}, {-2, -3}};
    assert(sol.minimumTotal(t2) == -4);

    return 0;
}
