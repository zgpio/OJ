#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>  //其中包含了stl_algobase
#include <list>
using namespace std;
const int N = 105;
int cheese[N][N];
int mov[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};  // 上下左右
int n;
int ans = 0;
void dfs(int need, int x, int y, int eat)
{
    for (int i = 0; i < 4; ++i) {  // 四个方向试探
        int tx = x, ty = y;
        tx += mov[i][0];
        ty += mov[i][1];
        if (!(0 <= tx && tx < n) || !(0 <= ty && ty < n)) continue;
        if (cheese[tx][ty] == 0) continue;
        int save = cheese[tx][ty];
        if (save > need) {
            eat += save;
            if (ans < eat) ans = eat;
            cheese[tx][ty] = 0;
            dfs(save, tx, ty, eat);
            eat -= save;
            cheese[tx][ty] = save;
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
    int k;
    while (cin >> n >> k && !(n == -1 && k == -1)) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) cin >> cheese[i][j];
        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //         cout << cheese[i][j] << " ";
        //     }
        //     std::cout << std::endl;
        // }
        dfs(0, 0, 0, cheese[0][0]);
        std::cout << ans << std::endl;
    }

    return 0;
}
