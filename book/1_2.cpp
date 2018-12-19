#include <stdio.h>
#include <string.h>

int f(int i, int k)
{
    int j;
    int sum = 0;
    if (k == 1) {
        return 1;
    }
    else {
        for (j = i + 1; j <= 26; j++) {
            sum += f(j, k - 1);
        }
    }
    return sum;
}  //第i个字母开头长度为k的数量

int ca(char a[])
{
    int i, j, cnt, n, len;
    int sum = 0;
    int k = strlen(a);
    for (i = 1; i < k; i++) {
        for (int j = 1; j <= 26; j++) {
            sum += f(j, i);
        }
    }  // 该字符串的位置就是小于k长度的数量
    int h = a[0] - 'a' + 1;
    for (int i = 1; i < h; i++) {
        sum += f(i, k);
    }  //加上小于开头字母的长度为k的数量

    cnt = h;
    for (i = 1; i < k; i++) {
        n = a[i] - 'a' + 1;
        len = k - i;
        for (j = cnt + 1; j < n; j++) {
            sum += f(j, len);
        }
        cnt = n;
    }  //再加上字符串中字母与其后面字母之间字母开头的k-i长度字符串的数量
    return sum + 1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input/1_2", "rt", stdin);
#endif
    int n;
    char a[6];  // len<=6
    long long x;
    scanf("%d", &n);
    getchar();
    while (n--) {
        x = 0;
        gets(a);
        x = ca(a);
        printf("%d\n", x);
    }
    return 0;
}
