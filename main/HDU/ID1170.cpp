#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>  //其中包含了stl_algobase
#include <list>
using namespace std;

const float EPSINON = 0.000001;
bool approximatelyEqual(float a, float b, float epsilon)
{
    return fabs(a - b) <= ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input/1170", "rt", stdin);
#endif
    int T;
    std::cin >> T;
    while (T--) {
        char oper;
        double A, B, ans;
        std::cin >> oper >> A >> B;
        switch (oper) {
            case '*':
                ans = A * B;
                break;
            case '-':
                ans = A - B;
                break;
            case '+':
                ans = A + B;
                break;
            case '/':
                ans = A / B;
                break;
            default:
                break;
        }
        if (!approximatelyEqual(ans, (long long)(ans), EPSINON)) {
            double tmp = (int)((ans * 100) + 0.5) / 100.0;
            printf("%.2lf\n", tmp);
        }
        else
            // Note:
            //  cout输出e表示法
            //  自动测试加入极端数据
            printf("%.0lf\n", ans);
    }

    return 0;
}
