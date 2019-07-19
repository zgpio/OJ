#include "lc/lc.h"
using namespace std;

// Runtime: 8 ms, faster than 69.63% of C++ online submissions for Triangle.
// Memory Usage: 9.5 MB, less than 100.00% of C++ online submissions for Triangle.
class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int l = triangle.size();
        int dp[l];
        dp[0] = triangle[0][0];
        for (int i = 1; i < l; ++i) {
            dp[i] = dp[i - 1] + triangle[i][i];
            for (int k = i - 1; k > 0; --k) {
                dp[k] = min(dp[k - 1], dp[k]) + triangle[i][k];
            }
            dp[0] = dp[0] + triangle[i][0];
        }
        int ret = numeric_limits<int>::max();
        for (int i = 0; i < l; ++i) {
            ret = min(dp[i], ret);
        }
        std::cout << ret << std::endl;
        return ret;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> t1 = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    assert(sol.minimumTotal(t1) == 11);
    vector<vector<int>> t2 = {{-1}, {-2, -3}};
    assert(sol.minimumTotal(t2) == -4);

    return 0;
}
