#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using LL = long long;

    int nthUglyNumber(int n, int a, int b, int c)
    {
        //看到n的范围应该马上联想到是, 典型的二分思路
        LL low = min({a, b, c}); //下边界显然是a、b、c中最小者
        LL high = static_cast<LL>(low) * n; //上边界是这个最小者的n倍

        LL res = Binary_Search(low, high, a, b, c, n);

        LL left_a = res % a;
        LL left_b = res % b;
        LL left_c = res % c;

        return res - min({left_a, left_b, left_c});
    }

private:
    //二分搜索
    LL Binary_Search(LL low, LL high, int a, int b, int c, LL n)
    {
        if (low >= high) return low;

        LL mid = (low + high) >> 1;

        LL MCM_a_b = LCM(a, b);
        LL MCM_a_c = LCM(a, c);
        LL MCM_b_c = LCM(b, c);
        LL MCM_a_b_c = LCM(MCM_a_b, c);

        //独立的丑数个数为, 当前数分别除以a、b、c的和,
        //减去当前数除以a、b、c两两间最小公倍数的和, 再加上当前数除以
        // a、b、c三者的最小公倍数
        LL count_n = mid / a + mid / b + mid / c - mid / MCM_a_b -
                     mid / MCM_b_c - mid / MCM_a_c + mid / MCM_a_b_c;

        if (count_n == n)
            return mid;
        else if (count_n < n)
            return Binary_Search(mid + 1, high, a, b, c, n);
        else
            return Binary_Search(low, mid - 1, a, b, c, n);
    }

    // 求最小公倍数(Least common multiple): 两数乘积除以最大公约数
    LL LCM(LL a, LL b)
    {
        LL Multi = a * b;

        while (b > 0) {
            LL tmp = a % b;
            a = b;
            b = tmp;
        }

        return Multi / a;
    }
};

int main(int argc, char *argv[])
{
    // 输入：n = 3, a = 2, b = 3, c = 5
    // 输出：4
    // 解释：丑数序列为 2, 3, 4, 5, 6, 8, 9, 10... 其中第 3 个是 4。
    Solution s;
    assert(s.nthUglyNumber(3, 2, 3, 5) == 4);

    return 0;
}
