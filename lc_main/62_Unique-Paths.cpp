#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n)
    {
        // 横向x轴, 纵向y轴
        vector<vector<int>> dp(m, vector<int>(n, 1));

        for (int x = 1; x < m; ++x) {
            for (int y = 1; y < n; ++y) {
                dp[x][y] = dp[x][y - 1] + dp[x - 1][y];
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main()
{
    Solution sol;
    assert(sol.uniquePaths(7, 3) == 28);
    assert(sol.uniquePaths(3, 2) == 3);

    return 0;
}
