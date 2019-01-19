#include <assert.h>
#include <cstdio>
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

// 7. Reverse Integer
class Solution {
public:
    int reverse(int x)
    {
        long long a = x;
        bool neg = false;
        if (a < 0) {
            neg = true;
            a = -a;
        }
        long long res = 0;
        while (a > 0) {
            res = res * 10 + a % 10;
            a /= 10;
        }
        if (neg) res = -res;

        if (numeric_limits<int>::min() <= res &&
            res <= numeric_limits<int>::max()) {
            std::cout << res << std::endl;
            return res;
        }
        else
            return 0;
    }
};

int main()
{
    Solution sol;
    assert(sol.reverse(123) == 321);
    assert(sol.reverse(-123) == -321);
    assert(sol.reverse(120) == 21);
    assert(sol.reverse(-2147483648) == 0);

    std::cout << "end" << std::endl;
    return 0;
}
