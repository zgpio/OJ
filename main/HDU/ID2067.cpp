#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifdef LOCAL_JUDGE
    freopen ("../../input/2067", "rt", stdin);
#endif

    long long map[36][36] = {};
    int cnt = 0;
    for(int i = 0; i < 36; i++)
        map[i][0] = 1;
    for(int i = 1; i < 36; i++)//遵循一定的计算序列
        for(int j = 1; j <= i; j++)
            map[i][j] = map[i - 1][j] + map[i][j - 1];
    int n;
    while(~scanf("%d", &n) && ~n)
        printf("%d %d %lld\n", ++cnt, n, 2 * map[n][n]);

    return 0;
}
