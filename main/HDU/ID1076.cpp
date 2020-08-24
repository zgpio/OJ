#include <bits/stdc++.h>
using namespace std;

int isLeap(int Y)
{
    if ((Y % 4 == 0 && Y % 100 != 0) or (Y % 400 == 0)) return 1;
    return 0;
}
/*
 * 公历纪年法中, 能被4整除的大多是闰年,
 * 但能被100整除而不能被400整除的年份不是闰年, 能被3200整除的也不是闰年,
 * 如1900年是平年, 2000年是闰年, 3200年不是闰年.
 */
int leapYear(int Y)
{
    int ret = 1;
    if (Y % 4 != 0)
        ret = 0;
    else {
        if (Y % 100 == 0 && Y % 400 != 0) ret = 0;
        if (Y % 3200 == 0) ret = 0;
    }
    return ret;
}

int main()
{
#ifdef LOCAL_JUDGE
    freopen("../../input/1076", "rt", stdin);
#endif
    int T;
    std::cin >> T;
    while (T--) {
        int Y, N;
        std::cin >> Y >> N;
        for (int i = 0; i < N; Y++) {
            if (isLeap(Y)) i++;
        }
        std::cout << Y - 1 << std::endl;
    }

    return 0;
}
