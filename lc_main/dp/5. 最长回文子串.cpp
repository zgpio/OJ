#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool dp[1000][1000];

   public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        if (n < 1)
            return "";
        for (int i = 0; i < n; i++)
            dp[i][i] = true;
        int li = 0, lj = 0;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                li = i, lj = i + 1;
            } else
                dp[i][i + 1] = false;
        }
        // NOTE: 如果连续两次出现全false, 就可以提前终止.
        for (int b = 2; b < n; ++b) {  // b=j-i
            for (int i = 0; i < n - b; i++) {
                int j = i + b;
                if (dp[i + 1][j - 1] && s[i] == s[j]) {
                    dp[i][j] = true;
                    li = i, lj = j;
                } else
                    dp[i][j] = false;
            }
        }

        return s.substr(li, lj - li + 1);
    }
};

int main()
{
    Solution s;
    assert(s.longestPalindrome("babad") == "aba");
    assert(s.longestPalindrome("cbbd") == "bb");
    assert(s.longestPalindrome("") == "");
    assert(s.longestPalindrome("a") == "a");
    assert(s.longestPalindrome("bb") == "bb");
    assert(s.longestPalindrome("caba") == "aba");
    assert(s.longestPalindrome("abcba") == "abcba");

    return 0;
}
