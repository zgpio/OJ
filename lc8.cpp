#include <assert.h>
#include <climits>
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

// 8. String to Integer (atoi)
class Solution {
public:
    int myAtoi(string str)
    {
        string::iterator i = str.begin();
        bool neg = false;
        // 跳过空格
        while (i != str.end() && *i == ' ') i++;
        if (*i == '-') {
            neg = true;
            i++;
        }
        else if (*i == '+') {
            neg = false;
            i++;
        }
        else if (!isdigit(*i)) {
            return 0;
        }
        long long res = 0;
        while (i != str.end() && isdigit(*i)) {
            res = res * 10 + (*i - '0');
            i++;
            if (res > INT_MAX || res < INT_MIN) break;
        }
        if (neg) res = -res;
        if (res < INT_MIN)
            return INT_MIN;
        else if (res > INT_MAX)
            return INT_MAX;
        else
            return res;
    }
};

int main()
{
    Solution sol;
    assert(sol.myAtoi("word with 4193") == 0);
    assert(sol.myAtoi("   -42") == -42);
    assert(sol.myAtoi("42") == 42);
    assert(sol.myAtoi("4193 with ") == 4193);
    assert(sol.myAtoi("-91283472332") == -2147483648);
    assert(sol.myAtoi("9223372036854775808") == 2147483647);

    std::cout << "end" << std::endl;
    return 0;
}
