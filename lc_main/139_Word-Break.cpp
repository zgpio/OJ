#include <bits/stdc++.h>
using namespace std;

// Runtime: 16 ms, faster than 51.06% of C++ online submissions for Word Break.
// Memory Usage: 14.3 MB, less than 36.88% of C++ online submissions for Word Break.
class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int n = s.size();
        bool dp[n];
        for (int i = 0; i < n; ++i) {
            dp[i] = false;
        }
        unordered_set<string> wd;
        for (auto i : wordDict)
            wd.insert(i);

        for (int i = 0; i < n; ++i) {
            string h = s.substr(0, i + 1);
            // std::cout << h << std::endl;
            if (wd.find(h) != wd.end()) {
                dp[i] = true;
                continue;
            }
            for (int j = 0; j < i; ++j) {
                if (dp[j]) {
                    string t = s.substr(j + 1, i - j);
                    // std::cout << t << std::endl;
                    if (wd.find(t) != wd.end()) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        // for(auto i: dp)
        //     std::cout << i << " ";
        // std::cout << std::endl;
        return dp[n - 1];
    }
};

int main()
{
    Solution sol;
    string s1 = "leetcode";
    vector<string> wd1 = {"leet", "code"};
    assert(sol.wordBreak(s1, wd1));

    string s2 = "applepenapple";
    vector<string> wd2 = {"apple", "pen"};
    assert(sol.wordBreak(s2, wd2));

    string s3 = "catsandog";
    vector<string> wd3 = {"cats", "dog", "sand", "and", "cat"};
    assert(!sol.wordBreak(s3, wd3));

    string s4 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    vector<string> wd4 = {"a", "aa", "aaa", "aaaa", "aaaaa"};
    assert(!sol.wordBreak(s4, wd4));
    return 0;
}
