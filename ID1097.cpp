#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>  //其中包含了stl_algobase
#include <list>
using namespace std;

// quick pow
// return A^n % mod
int qpow(int A, int n, int mod)
{
    int ans = 1;
    A %= mod;
    while (n) {
        if (n & 1) {
            ans = (ans * A) % mod;
        }  // 当n是奇数
        A = (A * A) % mod;
        n >>= 1;
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input/1097.txt", "rt", stdin);
#endif
    int n, m;

    while (~scanf("%d%d", &n, &m)) {
        printf("%d\n", qpow(n, m, 10));
    }

    return 0;
}
