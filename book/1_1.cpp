#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
#define int64 long long

int subNumber(char n[], int start, int end)
{
    char tmp[10];
    int subnum;
    if (start > end) return 0;
    strncpy(tmp, n + start, end - start + 1);
    sscanf(tmp, "%d", &subnum);
    return subnum;
}
// 统计数字问题
int main()
{
#ifdef LOCAL_JUDGE
    freopen("./input/1_1", "rt", stdin);
#endif
    // e.g.
    // n[0] n[1] n[2] n[3]
    //  1    2    3    4
    char n[10];  // n <= 10^9
    while (scanf("%s", n) != EOF) {
        int64 result[10] = {0};
        int i, j, k, len = strlen(n);
        int inc;
        for (i = 0; i < len; i++) {
            //  subl    k   subr
            // (0, i-1) i (i+1, len-1)
            k = subNumber(n, i, i);
            for (j = 0; j < 10; j++) {
                int subl = subNumber(n, 0, i - 1);
                if (j < k)
                    inc = (subl + 1) * pow(10, len - i - 1);
                else if (j == k) {
                    int subr = subNumber(n, i + 1, len - 1);
                    inc = subl * pow(10, len - i - 1) + (subr + 1);
                }
                else
                    inc = subl * pow(10, len - i - 1);
                result[j] += inc;
            }
        }
        for (i = 0; i < len; i++)
            result[0] -= pow(10, i);

        for (i = 0; i < 10; i++) {
            printf("%4lld ", result[i]);  // I64d
        }
        printf("\n");
    }
    return 0;
}
