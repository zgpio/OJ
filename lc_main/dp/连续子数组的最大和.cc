#include <iostream>
#include <vector>
using namespace std;
/*
    f[i]表示a[i]结尾的最大连续和

           ┌ f[i-1] + a[i]     f[i-1]>0
    f[i] = ┤
           └ a[i]              f[i-1]<=0
 */
class Solution
{
   public:
    int maxSubArray(vector<int>& nums)
    {
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            nums[i] += max(nums[i - 1], 0);
            res = max(res, nums[i]);
        }
        return res;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    assert(s.maxSubArray(nums) == 6);
    return 0;
}
