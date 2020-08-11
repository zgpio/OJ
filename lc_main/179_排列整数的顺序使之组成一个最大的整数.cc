#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int> &nums)
    {
        vector<string> vs;
        for (auto i : nums) {
            vs.push_back(to_string(i));
        }
        sort(vs.begin(), vs.end(), [](string &a, string &b) {
            string s1 = a + b;
            string s2 = b + a;
            return s1 > s2;
        });
        string rv;
        for (auto i : vs)
            rv += i;
        rv.erase(0, rv.find_first_not_of("0"));
        if (rv.size() == 0) return "0";
        return rv;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    {
        vector<int> v{3, 30, 34, 5, 9};
        assert(s.largestNumber(v) == "9534330");
    }
    {
        vector<int> v{0, 0};
        assert(s.largestNumber(v) == "0");
    }

    return 0;
}
