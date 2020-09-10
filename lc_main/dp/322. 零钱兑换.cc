#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  /*
  F(i) 为组成金额 i 所需最少的硬币数量, 假设在计算 F(i) 之前, 我们已经计算出
  F(0)~F(i-1) 的答案.  则 F(i) 对应的转移方程应为

  F(i) = min{F(i - c_j)} + 1 ,  j=0, ...,  n-1

  其中 c_j 代表的是第 j 枚硬币的面值, 即我们枚举最后一枚硬币面额是 c_j,
  那么需要从 i-c_j 这个金额的状态 F(i-c_j) 转移过来,
  再算上枚举的这枚硬币数量 1 的贡献, 由于要硬币数量最少,
  所以 F(i) 为前面能转移过来的状态的最小值加上枚举的硬币数量 1 .
   */

  int coinChange(vector<int> &coins, int amount) {
    int Max = amount + 1;
    vector<int> dp(amount + 1, Max);
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i) {
      for (int j = 0; j < (int)coins.size(); ++j) {
        if (coins[j] <= i) {
          dp[i] = min(dp[i], dp[i - coins[j]] + 1);
        }
      }
    }
    return dp[amount] > amount ? -1 : dp[amount];
  }
};

int main() {
  Solution s;
  vector<int> coins{1, 2, 5};

  assert(s.coinChange(coins, 11) == 3);

  return 0;
}
