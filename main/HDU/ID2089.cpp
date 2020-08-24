#include <bits/stdc++.h>
using namespace std;
const int LEN = 1000000;
int a[LEN] = {0};
int main()
{
#ifdef LOCAL_JUDGE
    freopen ("input.txt", "rt", stdin);
#endif
    int n, m;
    char str[10];
    for(int i = 1; i < 1000000; i++) {
        sprintf(str, "%d", i);
        if(strstr(str, "62") == NULL && strchr(str, '4') == NULL)
            a[i] = a[i - 1] + 1;
        else
            a[i] = a[i - 1];
    }
    while(scanf("%d%d", &n, &m) != EOF && (n || m))
        printf("%d\n", a[m] - a[n - 1]);

    return 0;
}
