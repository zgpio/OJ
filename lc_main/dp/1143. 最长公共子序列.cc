#include <iostream>
#include <string>
using namespace std;

class Solution
{
   public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int l1 = text1.size(), l2 = text2.size();
        int dp[l1 + 1][l2 + 1];  // dp[i][j] 表示长度i的s1与长度j的s2的最优解
        for (int i = 0; i <= l1; i++)
            dp[i][0] = 0;
        for (int j = 0; j <= l2; j++)
            dp[0][j] = 0;
        for (int i = 1; i <= l1; i++) {
            for (int j = 1; j <= l2; j++) {
                if (text1[i - 1] == text2[j - 1]) {  // NOTE 字符串索引0-based
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        return dp[l1][l2];
    }
};
int main(int argc, char *argv[])
{
    Solution s;
    assert(s.longestCommonSubsequence("abcde", "ace") == 3);
    assert(s.longestCommonSubsequence("abc", "def") == 0);
    return 0;
}
