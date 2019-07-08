#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <list>
#include <time.h>
using namespace std;

int comp(const void *a, const void *b)
{
    return *((int *)a) - *((int *)b);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "rt", stdin);
#endif
    int n;
    int a[100];
    while(scanf("%d", &n) != EOF) {
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        qsort(a, n, sizeof(int), comp);
        int cnt = 0;
        for (int i = 1; i < n; i++) {//去重
            if (a[i] == a[i - 1]) {
                a[i - 1] = -1;
                cnt ++;//计数
            }
        }
        printf("%d\n", n - cnt);
        int first = 1;
        for(int i = 0; i < n; i++)
            if (a[i] != -1) {
                if(first) {
                    first = 0;
                    printf("%d", a[i]);
                } else
                    printf(" %d", a[i]);
            }
        printf("\n");
    }
    return 0;
}
