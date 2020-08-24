#include <bits/stdc++.h>
using namespace std;

// 自底向上计算
//
//         x^7
//      /       \
//    x^4        x^3
//   /   \      /   \
// x^2   x^2   x^2   x
// /  \  /  \  /  \  |
// x  x  x  x  x  x  x
double PowerNormal(double base, int exponent)
{
    if (exponent == 0) {
        return 1;
    } else if (exponent == 1) {
        return base;
    }

    double res = 1, temp = base;
    while (exponent != 0) {
        if ((exponent & 1) == 1)  // 如果当前指数为奇数
        {
            res *= temp;
        }
        temp *= temp;
        exponent >>= 1;
    }
    return res;
}

template <typename T>
bool essentiallyEqual(T a, T b, T epsilon)
{
    return fabs(a - b) <= ((fabs(a) > fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}
int main(int argc, char *argv[])
{
    assert(essentiallyEqual(PowerNormal(0.2, 3), 0.008, std::numeric_limits<double>::epsilon()));
    assert(essentiallyEqual(PowerNormal(0.1, 3), 0.001, std::numeric_limits<double>::epsilon()));
    return 0;
}
