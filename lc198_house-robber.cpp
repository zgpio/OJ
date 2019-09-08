#include "lc/lc.h"
using namespace std;

class Solution {
public:
    int rob(vector<int> &nums)
    {
        const int n = nums.size();
        if (n == 0)
            return 0;
        else if (n == 1)
            return nums[0];
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        }
        int ret = 0;
        for (auto i : dp)
            if (i > ret) ret = i;
        return ret;
    }
};

int main()
{
    Solution sol;
    vector<int> t1 = {1, 2, 3, 1};
    assert(sol.rob(t1) == 4);

    vector<int> t2 = {2, 7, 9, 3, 1};
    assert(sol.rob(t2) == 12);
    vector<int> t3 = {1, 2};
    assert(sol.rob(t3) == 2);

    vector<int> t4 = {2};
    assert(sol.rob(t4) == 2);
    return 0;
}
