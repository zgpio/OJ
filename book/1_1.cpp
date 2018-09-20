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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input", "rt", stdin);
#endif
    // e.g.
    // n[0] n[1] n[2] n[3]
    //  1    2    3   4
    char n[10];  // n <= 10^9
    while (scanf("%s", n) != EOF) {
        cout << subNumber("1234", 0, 0) << endl;
        cout << subNumber("1234", 2, 1) << endl;
        cout << subNumber("1234", 0, 3) << endl;
        int64 result[10] = {0};
        int i, j, k, len = strlen(n);
        int inc;
        for (i = len - 1; i >= 0; i--) {
            k = subNumber(n, i, i);
            for (j = 0; j < 10; j++) {
                if (j < k)
                    inc = (subNumber(n, 0, i - 1) + 1) * pow(10, len - i - 1);
                else if (j == k)
                    inc = (subNumber(n, 0, i - 1)) * pow(10, len - i - 1) +
                          (subNumber(n, i + 1, len - 1) + 1);
                else
                    inc = (subNumber(n, 0, i - 1)) * pow(10, len - i - 1);
                result[j] += inc;
            }
        }
        for (i = 0; i < len - 1; i++) {
            result[0] -= pow(10, len - i - 2) * 9 * (i + 1);
        }
        result[0] -= len;
        for (i = 0; i < 10; i++) {
            printf("%I64d ", result[i]);
        }
        printf("\n");
    }
    return 0;
}
