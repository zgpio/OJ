#include "lc/lc.h"
using namespace std;

// Runtime: 8 ms, faster than 58.27% of C++ online submissions for Find Peak Element.
// Memory Usage: 8.8 MB, less than 25.44% of C++ online submissions for Find Peak Element.
class Solution {
public:
    int findPeakElement(vector<int> &nums)
    {
        const int n = nums.size() + 2;
        assert(n > 2);
        nums.insert(nums.begin(), numeric_limits<int>::min());
        nums.push_back(numeric_limits<int>::min());
        int ans;
        int i = 0, j = 1, k = 2;
        while (k < n) {
            if (nums[j] > nums[i] && nums[j] > nums[k]) {
                ans = j;
                break;
            }
            ++i;
            ++j;
            ++k;
        }
        return ans - 1;
    }
};

int main()
{
    Solution sol;
    vector<int> t1{1, 2, 1, 3, 5, 6, 4};
    assert(sol.findPeakElement(t1) == 1);
    return 0;
}
