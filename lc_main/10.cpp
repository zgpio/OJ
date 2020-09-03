#include <bits/stdc++.h>
using namespace std;

class Solution
{
   public:
    bool isMatch(string s, string p)
    {
        int m = s.size();
        int n = p.size();

        auto matches = [&](int i, int j) {
            if (i == 0) {
                return false;
            }
            if (p[j - 1] == '.') {
                return true;
            }
            return s[i - 1] == p[j - 1];
        };

        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        f[0][0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    f[i][j] |= f[i][j - 2];
                    if (matches(i, j - 1)) {
                        f[i][j] |= f[i - 1][j];
                    }
                } else {
                    if (matches(i, j)) {
                        f[i][j] |= f[i - 1][j - 1];
                    }
                }
            }
        }
        return f[m][n];
    }
};

int main()
{
    Solution sol;
    assert(sol.isMatch("abb", "a.b") == true);
    assert(sol.isMatch("abb", "a*.b") == true);
    assert(sol.isMatch("aaab", "a*ab") == true);
    assert(sol.isMatch("ab", ".*") == true);
    assert(sol.isMatch("aba", ".*a") == true);
    assert(sol.isMatch("aab", "c*a*b*") == true);
    assert(sol.isMatch("aaa", "aaaa") == false);
    assert(sol.isMatch("a", "ab*") == true);
    assert(sol.isMatch("bbbba", ".*a*a") == true);

    return 0;
}
