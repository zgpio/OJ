#include "lc/lc.h"
using namespace std;

vector<vector<string>> keys = {
    {"a", "b", "c"}, {"d", "e", "f"},      {"g", "h", "i"},
    {"j", "k", "l"}, {"m", "n", "o"},      {"p", "q", "r", "s"},
    {"t", "u", "v"}, {"w", "x", "y", "z"},
};
class Solution {  // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Letter Combinations of a Phone Number.
public:
    vector<string> letterCombinations(string digits)
    {
        queue<string> ret;
        for (auto i : digits) {
            vector<string> t = keys[i - '2'];

            if (ret.empty()) {
                for (auto i : t) ret.push(i);
            }
            else {
                int sz = ret.size();
                while (sz--) {
                    string top = ret.front();
                    ret.pop();
                    for (auto k : t) {
                        string t = top;
                        t += k;
                        ret.push(t);
                    }
                }
            }
        }

        vector<string> ans;
        while (!ret.empty()) {
            ans.push_back(ret.front());
            // std::cout << ret.front() << std::endl;
            ret.pop();
        }
        return ans;
    }
};

int main()
{
    Solution sol;

    vector<string> a1{"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
    assert(sol.letterCombinations("23") == a1);

    return 0;
}
