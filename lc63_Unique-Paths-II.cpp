#include "lc/lc.h"
using namespace std;

class Solution {
    int ans;
    int m, n;
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        ans = 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        dfs(obstacleGrid, 0, 0);
        return ans;
    }
    void dfs(vector<vector<int>> &a, int x, int y)
    {
        if(x==m-1 && y ==n-1)
        {
            ans++;
        }
        if(x+1<m && a[x+1][y]==0)
            dfs(a, x+1, y);
        if(y+1<n && a[x][y+1]==0)
            dfs(a, x, y+1);
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> t1 = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    assert(sol.uniquePathsWithObstacles(t1) == 2);

    return 0;
}
