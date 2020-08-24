#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifdef LOCAL_JUDGE
    freopen ("input.txt", "rt", stdin);
#endif
    int C;
    scanf("%d", &C);
    while(C--) {
        int N;
        int dp[105][105] = {0};
        scanf("%d", &N);//1<=N<=100
        int r, c;

        for(r = 1; r <= N; r++) {
            for(c = 1; c <= r; c++) {
                int in;
                scanf("%d", &in);
                if(dp[r - 1][c - 1] > dp[r - 1][c])
                    dp[r][c] = dp[r - 1][c - 1] + in;
                else
                    dp[r][c] = dp[r - 1][c] + in;
            }
        }
        int max = -1;
        for(c = 1; c <= N; c++) {
            if(dp[N][c] > max)
                max = dp[N][c];
        }
        printf("%d\n", max);
    }

    return 0;
}
