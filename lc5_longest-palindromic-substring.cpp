#include "lc/lc.h"
using namespace std;

class Solution {
    bool dp[1000][1000];

public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        if (n < 1) return "";
        for (int i = 0; i < n; i++)
            dp[i][i] = true;
        int li = 0, lj = 0;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                li = i, lj = i + 1;
            }
            else
                dp[i][i + 1] = false;
        }
        int b;
        // NOTE: 如果连续两次出现全false, 就可以提前终止.
        for (b = 2; b < n; ++b) {

            for (int i = 0, j = b; i < n - b && j < n; i++, j++) {
                std::cout << i << "->" << j << "  ";
                if (dp[i + 1][j - 1] && s[i] == s[j]) {
                    dp[i][j] = true;
                    li = i, lj = j;
                }
                else
                    dp[i][j] = false;
            }
        }

        std::cout << s.substr(li, lj - li + 1) << std::endl;
        return s.substr(li, lj - li + 1);
    }
};

int main()
{
    Solution sol;
    assert(sol.longestPalindrome("babad") == "aba");
    assert(sol.longestPalindrome("cbbd") == "bb");
    assert(sol.longestPalindrome("") == "");
    assert(sol.longestPalindrome("a") == "a");
    assert(sol.longestPalindrome("bb") == "bb");
    assert(sol.longestPalindrome("caba") == "aba");
    assert(sol.longestPalindrome("abcba") == "abcba");

    return 0;
}
