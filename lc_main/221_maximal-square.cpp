#include "lc/lc.h"
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        const int n = matrix.size();
        if (n == 0) return 0;
        const int m = matrix[0].size();
        // NOTE: dp[i][j]表示以(i,j)为右底角的正方形边长
        vector<vector<int>> dp(n, vector<int>(m, 0));

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = min(dp[i - 1][j - 1],
                                       min(dp[i][j - 1], dp[i - 1][j])) +
                                   1;
                    if (dp[i][j] > ret) ret = dp[i][j];
                }
                else
                    dp[i][j] = 0;
            }
        }

        return ret * ret;
    }
};

// TLE
class Solution2 {
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        int l = min(n, m);
        for (int i = l; i > 0; i--) {
            std::cout << "l=" << i << ": ";
            for (int sx = 0; sx <= n - i; sx++) {
                for (int sy = 0; sy <= m - i; sy++) {
                    std::cout << sx << "," << sy << "  ";
                    if (check(matrix, sx, sy, i)) return i * i;
                }
            }
            std::cout << std::endl;
        }
        return 0;
    }

    bool check(vector<vector<char>> m, int x, int y, int l)
    {
        for (int i = x; i < x + l; i++) {
            for (int j = y; j < y + l; j++) {
                if (m[i][j] == '0') return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    // clang-format off
    vector<vector<char>> t1 = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}};
    // clang-format on

    vector<vector<char>> t2 = {};
    vector<vector<char>> t3 = {{'0'}};
    vector<vector<char>> t4 = {{'1'}};
    assert(sol.maximalSquare(t1) == 4);
    assert(sol.maximalSquare(t2) == 0);
    assert(sol.maximalSquare(t3) == 0);
    assert(sol.maximalSquare(t4) == 1);

    return 0;
}
