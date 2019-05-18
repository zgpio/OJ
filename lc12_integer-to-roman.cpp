#include <assert.h>
#include <cstdio>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <string>
#include <tuple>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string intToRoman(int num)
    {
        int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        char sign[][3] = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                          "XL", "X",  "IX", "V",  "IV", "I"};
        string ret;
        int cur = num;
        for (int i = 0; i < 13; ++i) {
            int a = cur / val[i];
            if (a != 0) {
                for (int j = 0; j < a; ++j) ret.append(sign[i]);
            }
            cur %= val[i];
        }
        return ret;
    }
};

int main()
{
    Solution sol;
    assert(sol.intToRoman(3) == "III");
    assert(sol.intToRoman(4) == "IV");
    assert(sol.intToRoman(9) == "IX");
    assert(sol.intToRoman(58) == "LVIII");
    assert(sol.intToRoman(1994) == "MCMXCIV");
    std::cout << "end" << std::endl;
    return 0;
}
