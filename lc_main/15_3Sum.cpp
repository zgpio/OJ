#include <bits/stdc++.h>
#include "lc/util.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> res;
        if (n == 0) return res;
        // sort the input vector in ascending order
        sort(nums.begin(), nums.end());
        // optimization check: no solution
        if (nums.front() > 0 || nums.back() < 0) return res;

        for (int i = 0; i < n - 2; ++i) {
            // optimiaztion check: no need to continue the loop
            if (nums[i] > 0) break;
            // move fixed number index to skip the repeated values
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1, k = n - 1; j < k;) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    // find possible solution
                    res.push_back({nums[i], nums[j], nums[k]});
                    // move both left and right indexes
                    ++j;
                    --k;
                    // move left index to skip the repeated values
                    while (j < k && nums[j] == nums[j - 1]) ++j;
                    // move right index to skip the repeated values
                    while (j < k && nums[k] == nums[k + 1]) --k;
                }
                else if (sum < 0) {
                    // move left index to increase sum
                    ++j;
                }
                else {
                    // move right index to decrease sum
                    --k;
                }
            }
        }

        return res;
    }
};

int main()
{
    Solution sol;

    vector<int> t{-1, 0, 1, 2, -1, -4};
    vector<vector<int>> a{{-1, -1, 2}, {-1, 0, 1}};

    assert(sol.threeSum(t) == a);

    return 0;
}
