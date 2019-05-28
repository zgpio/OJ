#include <assert.h>
#include <climits>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <string>
#include <tuple>
#include <unordered_map>
using namespace std;

class Solution {
public:
    double myPow(double x, int n)
    {
        long nn = n;
        bool neg = false;
        if (nn < 0) {
            neg = true;
            nn = -nn;
        }

        if (nn == 0)
            return 1;
        else if (nn == 1)
            return neg ? 1.0 / x : x;

        double half = myPow(x, nn / 2);

        double ret = half * half;
        if ((nn & 1) == 1) {  // 若是奇数
            ret *= x;
        }
        return neg ? 1.0 / ret : ret;
    }
};

class Solution2 {  // Runtime beats 100% of cpp submissions.
public:
    double myPow(double x, int n)
    {
        long nn = n;
        if (nn < 0) {
            return 1.0 / _pow(x, -nn);
        }
        else
            return _pow(x, nn);
    }
    double _pow(double x, long n)
    {
        if (n == 0)
            return 1;
        else if (n == 1)
            return x;

        double half = myPow(x, n / 2);

        double ret = half * half;
        if ((n & 1) == 1) {  // 若是奇数
            ret *= x;
        }
        return ret;
    }
};

int main()
{
    Solution2 sol;

    assert((1 & 1) == 1);
    assert((2 & 1) == 0);
    std::cout << sol.myPow(2.1, 3) << std::endl;
    std::cout << sol.myPow(2.0, 10) << std::endl;
    std::cout << sol.myPow(2.0, -2) << std::endl;
    std::cout << sol.myPow(1.0, -2147483648) << std::endl;
    std::cout << sol.myPow(8.95371, -1) << std::endl;

    // TODO: 浮点数比较
    // assert(sol.myPow(2.10, 3) == 9.261);

    return 0;
}
