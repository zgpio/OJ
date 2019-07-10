#include "lc/lc.h"
using namespace std;

class Solution {
    int ans;
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
    }
    void dfs(int x, int y, int )
    {
        if(x)
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> t1 = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    assert(sol.uniquePathsWithObstacles(t1) == 2);

    return 0;
}
