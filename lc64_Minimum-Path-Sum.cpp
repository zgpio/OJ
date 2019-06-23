#include <algorithm>
#include <assert.h>
#include <climits>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <string>
#include <tuple>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        // x轴横向, y轴纵向
        int m = grid.size();
        int n = grid[0].size();
        // vector<vector<int>> dp(m, vector<int>(n, 0));
        vector<vector<int>> dp = grid;
        for (int y = 1; y < m; ++y)
            dp[y][0] += dp[y - 1][0];
        for (int x = 1; x < n; ++x)
            dp[0][x] += dp[0][x - 1];

        for (int x = 1; x < n; ++x) {
            for (int y = 1; y < m; ++y) {
                dp[y][x] += min(dp[y - 1][x], dp[y][x - 1]);
            }
        }
        return dp[m - 1][n - 1];
    }

private:
    // int ret = fun(grid, 0, 0, grid[0][0]);
    // TODO: runcase [[1]]能过，但是提交后同样的样例错误
    int fun(vector<vector<int>> &grid, int x, int y, int sum)
    {
        static int minl = numeric_limits<int>::max();
        int m = grid.size();
        int n = grid[0].size();
        if (sum > minl) return minl;
        if (x == n - 1 && y == m - 1) {
            minl = min(sum, minl);
            return minl;
        }

        int nx, ny, nminl = numeric_limits<int>::max();
        nx = x + 1, ny = y;
        if ((0 <= nx && nx < n) && (0 <= ny && ny < m)) {
            int right = fun(grid, nx, ny, sum + grid[nx][ny]);
            nminl = min(right, nminl);
        }

        nx = x, ny = y + 1;
        if ((0 <= nx && nx < n) && (0 <= ny && ny < m)) {
            int down = fun(grid, nx, ny, sum + grid[nx][ny]);
            nminl = min(down, nminl);
        }
        return nminl;
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> t1 = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    vector<vector<int>> t2 = {{1}};

    assert(sol.minPathSum(t1) == 7);
    assert(sol.minPathSum(t2) == 1);

    return 0;
}
