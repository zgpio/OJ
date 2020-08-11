#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution
{
   public:
    int numIslands(vector<vector<char>>& grid)
    {
        int n = grid.size();
        if (n == 0)
            return 0;
        int m = grid[0].size();
        vector<vector<bool>> flag(n, vector<bool>(m, false));
        int rv = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!flag[i][j] && grid[i][j] == '1') {
                    dfs(grid, flag, i, j);
                    rv += 1;
                }
            }
        }
        return rv;
    }
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& flag, int i, int j)
    {
        int n = grid.size();
        int m = grid[0].size();
        if ((0 <= i && i < n) && (0 <= j && j < m)) {
            if (grid[i][j] == '1' && !flag[i][j]) {
                flag[i][j] = true;
                dfs(grid, flag, i + 1, j);
                dfs(grid, flag, i - 1, j);
                dfs(grid, flag, i, j + 1);
                dfs(grid, flag, i, j - 1);
            }
        }
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    // clang-format off
    {
        vector<vector<char>> grid = {
            {'1', '1', '1', '1', '0'},
            {'1', '1', '0', '1', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '0', '0', '0'}};
        assert(s.numIslands(grid) == 1);
    }
    {
        vector<vector<char>> grid = {};
        assert(s.numIslands(grid) == 0);
    }

    return 0;
}
