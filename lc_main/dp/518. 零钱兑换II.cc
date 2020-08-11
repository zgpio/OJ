#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

/* 完全背包问题, 求解装满背包方案数
   amount = 5, coins = [1,2,5]

      │ 0  1  2  3  4  5
   ───┼─────────────────
    0 │ 1  0  0  0  0  0
    1 │ 1  1  1  1  1  1
    2 │ 1  1  2  2  3  3
    3 │ 1  1  2  2  3  4

    F[i,v] 表示i个面值, 总值为v时的组合数
             ┌ keep it                  v<Ci
    F[i,v] = ┤
             └ F(i-1,v) + F(i,v-Ci)     v>=Ci  不选Ci + 选Ci
*/
class Solution
{
   public:
    int change(int amount, vector<int>& coins)
    {
        // if(amount==0) return 1;
        // else if(coins.size()==0) return 0;

        int dim1 = coins.size();
        int dim2 = amount + 1;
        int dp[dim2];
        for (int i = 1; i < dim2; i++)
            dp[i] = 0;
        dp[0] = 1;

        for (int i = 0; i < dim1; i++) {
            for (int j = coins[i]; j < dim2; j++) {
                dp[j] = dp[j - coins[i]] + dp[j];
            }
        }
        return dp[dim2 - 1];
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    vector<int> coins{1, 2, 5};
    assert(s.change(5, coins) == 4);
    return 0;
}
