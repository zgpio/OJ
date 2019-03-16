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

// 9. Palindrome Number
class Solution {
public:
    bool isPalindrome(int x)
    {
        if (x < 0) return false;
        long long t = x;
        long long res = 0;
        while (t > 0) {
            res = res * 10 + t % 10;
            t /= 10;
        }
        if (res - x == 0)
            return true;
        else
            return false;
    }
};

int main()
{
    Solution sol;
    assert(sol.isPalindrome(121) == true);
    assert(sol.isPalindrome(-121) == false);
    assert(sol.isPalindrome(10) == false);

    std::cout << "end" << std::endl;
    return 0;
}
