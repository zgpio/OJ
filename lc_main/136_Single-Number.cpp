#include <bits/stdc++.h>
using namespace std;

// Runtime: 24 ms, faster than 27.91% of C++ online submissions for Single
// Number. Memory Usage: 11.8 MB, less than 5.23% of C++ online submissions for Single Number.
class Solution {
public:
    int singleNumber(vector<int> &nums)
    {
        map<int, int> m;
        for (auto i : nums) {

            auto search = m.find(i);
            if (search != m.end()) {
                search->second++;
            }
            else {
                m[i] = 1;
            }
        }
        int ret = -1111111;
        for (auto i : m) {
            if (i.second == 1) {
                ret = i.first;
                break;
            }
        }
        return ret;
    }
};

int main()
{
    Solution sol;
    vector<int> t1{2, 2, 1};
    vector<int> t2{4, 1, 2, 1, 2};
    vector<int> t3{2};

    assert(sol.singleNumber(t1) == 1);
    assert(sol.singleNumber(t2) == 4);
    assert(sol.singleNumber(t3) == 2);

    return 0;
}
