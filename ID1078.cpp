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

void dfs(int need, int x, int y, int eatd)
{
    for (int i = 0; i < 4; ++i) {  // 四个方向试探
        int nx = x + mov[i][0], ny = y + mov[i][1];
        if (!(0 <= nx && nx < n) || !(0 <= ny && ny < n)) continue;
        if (cheese[nx][ny] == 0) continue;
        int next = cheese[nx][ny];
        if (next > need) {
            eatd += next;
            cheese[nx][ny] = 0;
            if (ans < eatd) ans = eatd;
            dfs(next, nx, ny, eatd);
            eatd -= next;
            cheese[nx][ny] = next;
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input/1078", "rt", stdin);
#endif
    int k;
    while (cin >> n >> k && !(n == -1 && k == -1)) {
        ans = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) cin >> cheese[i][j];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << cheese[i][j] << " ";
            }
            std::cout << std::endl;
        }
        dfs(0, 0, 0, cheese[0][0]);
        std::cout << ans << std::endl;
    }

    return 0;
}
