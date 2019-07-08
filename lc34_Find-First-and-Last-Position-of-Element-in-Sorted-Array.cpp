#include "lc/lc.h"
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        // 二分查找后, 向两侧找边界
        if (binary_search(nums.begin(), nums.end(), target)) {
            auto l = lower_bound(nums.begin(), nums.end(), target);
            auto u = upper_bound(nums.begin(), nums.end(), target);
            int left = l - nums.begin();
            int right = u - nums.begin() - 1;
            return vector<int>{left, right};
        }
        else
            return vector<int>{-1, -1};
    }
};

int main()
{
    Solution sol;
    vector<int> t1 = {5, 7, 7, 8, 8, 10}, a1 = {3, 4};
    vector<int> t2 = {5, 7, 7, 8, 8, 10}, a2 = {-1, -1};
    vector<int> a3 = {0, 0};
    assert(sol.searchRange(t1, 8) == a1);
    assert(sol.searchRange(t2, 6) == a2);
    assert(sol.searchRange(t2, 5) == a3);

    return 0;
}
