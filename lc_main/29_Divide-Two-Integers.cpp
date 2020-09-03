#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor)
    {
        typedef long long ll;
        // Note: 在传递给abs之前转换ll
        ll A = dividend, B = divisor;
        int sign;
        if ((A < 0 && B < 0) || (A > 0 && B > 0))
            sign = 1;
        else
            sign = -1;
        if (A == INT_MIN && B == -1) {
            return INT_MAX;
        }
        else if (abs(B) == 1) {
            return A * B;
        }

        ll a = abs(A), b = abs(B);
        ll shift = 0;
        ll sum = 0;
        while (a >= b) {
            if ((b << 1) > a) {
                a = a - b;
                b = abs(B);
                sum += 1 << shift;
                shift = 0;
            }
            else {
                b <<= 1;
                shift++;
            }
        }
        ll ret = sum * sign;
        return ret;
    }
};

int main()
{
    Solution sol;

    assert(sol.divide(10, 3) == 3);
    assert(sol.divide(1, 3) == 0);
    assert(sol.divide(7, -3) == -2);
    assert(sol.divide(18, 1) == 18);
    assert(sol.divide(-2147483648, -1) == 2147483647);
    assert(sol.divide(8, 2) == 4);
    assert(sol.divide(-2147483648, 2) == -1073741824);
    assert(sol.divide(-2147483648, -2147483648) == 1);

    return 0;
}
