#include <bits/stdc++.h>
using namespace std;

class Solution
{
   public:
    bool canJump(vector<int>& nums)
    {
        const int n = nums.size();
        // 判断能否越过0~n-2位置上的0
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] == 0) {
                // 查找是否存在可以越过0的值
                int j = i - 1;
                while (j >= 0) {
                    if (nums[j] > i - j)
                        break;
                    else
                        j--;
                }
                if (j < 0)
                    return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;

    {
        vector<int> nums{2, 3, 1, 1, 4};
        assert(s.canJump(nums));
    }
    {
        vector<int> nums{3, 2, 1, 0, 4};
        assert(s.canJump(nums) == false);
    }
    {
        vector<int> nums{2, 0, 0};
        assert(s.canJump(nums));
    }
    {
        vector<int> nums{1, 0, 0};
        assert(s.canJump(nums) == false);
    }
    {
        vector<int> nums{0};
        assert(s.canJump(nums));
    }

    return 0;
}
