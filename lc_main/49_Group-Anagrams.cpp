#include <bits/stdc++.h>
using namespace std;

// sort using a custom function object
struct {
    bool operator()(string a, string b) const
    {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        return a < b;
    }
} customLess;
struct {
    bool operator()(string a, string b) const
    {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        return a == b;
    }
} customEqual;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        sort(strs.begin(), strs.end(), customLess);
        // for (auto i : strs) std::cout << i << " ";
        // std::cout << std::endl;
        vector<vector<string>> res;
        vector<string> t;
        for (auto i = strs.begin(); i < strs.end(); ++i) {
            if (t.empty()) {
                t.push_back(*i);
            }
            else {
                if (customEqual(*i, *(i - 1)))
                    t.push_back(*i);
                else {
                    res.push_back(t);
                    t.clear();
                    t.push_back(*i);
                }
            }
        }
        res.push_back(t);
        // for (auto i : res) {
        //     for (auto j : i) {
        //         std::cout << j << " ";
        //     }
        //     std::cout << std::endl;
        // }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<vector<string>> a1 = {
        {"ate", "eat", "tea"}, {"nat", "tan"}, {"bat"}};
    vector<string> t1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    sol.groupAnagrams(t1);
    return 0;
}
