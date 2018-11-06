#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>  //其中包含了stl_algobase
#include <list>
using namespace std;
const int M = 102;
// int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};  // 上下左右
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int n, k, mat[M][M], dp[M][M];

bool check(int x, int y)
{
    if (x < 0 || y < 0 || x >= n || y >= n) return false;
    return true;
}

int dfs(int x, int y)
{
    if (dp[x][y] != -1) return dp[x][y];
    int sum = 0;
    for (int p = 0; p < 4; ++p)
        for (int i = 1; i <= k; ++i) {
            int nx = x + i * dir[p][0];  //方向
            int ny = y + i * dir[p][1];
            if (check(nx, ny) && mat[x][y] < mat[nx][ny])
                sum = max(sum, dfs(nx, ny));  //找到相邻四个方向到此点的最优
        }
    return dp[x][y] = sum + mat[x][y];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input/1078", "rt", stdin);
#endif
    while (cin >> n >> k && !(n == -1 && k == -1)) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                cin >> mat[i][j];
            }
        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //         cout << cheese[i][j] << " ";
        //     }
        //     std::cout << std::endl;
        // }
        memset(dp, -1, sizeof(dp));
        dfs(0, 0);
        cout << dp[0][0] << endl;
    }
    return 0;
}
