#include "lc/lc.h"
using namespace std;

//    /│
//   / │
//  /  │
// ────┼────
//     │  /
//     │ /
//     │/
class Solution
{
   public:
    // 注意数组中不存在重复的元素
    int search(vector<int>& nums, int target)
    {
        const int n = nums.size();
        int l = 0, r = n - 1;

        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] == target) return m;
            if (nums[0] <= nums[m]) {                         // 如果 m 落在前半段
                if (nums[0] <= target && target < nums[m]) {  // 如果 target 落在前半段
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            } else {
                if (nums[m] < target && target <= nums[n - 1]) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;

    vector<int> t1 = {4, 5, 6, 7, 0, 1, 2};
    vector<int> t2 = {3, 1};
    vector<int> t3 = {5, 1, 3};
    assert(sol.search(t1, 0) == 4);
    assert(sol.search(t1, 3) == -1);
    assert(sol.search(t2, 4) == -1);
    assert(sol.search(t3, 5) == 0);
    return 0;
}
