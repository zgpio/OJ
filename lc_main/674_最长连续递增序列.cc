#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int> &nums)
    {
        if (nums.size() == 0) return 0;
        int l = 1;
        int ans = l;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1])
                l++;
            else {
                if (l > ans) ans = l;
                l = 1;
            }
        }
        if (l > ans) ans = l;
        return ans;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    {
        vector<int> nums = {1, 3, 5, 4, 7};
        assert(s.findLengthOfLCIS(nums) == 3);
    }
    {
        vector<int> nums = {2, 2, 2, 2, 2};
        assert(s.findLengthOfLCIS(nums) == 1);
    }
    {
        vector<int> nums = {1, 3, 5, 7};
        assert(s.findLengthOfLCIS(nums) == 4);
    }
    {
        vector<int> nums = {};
        assert(s.findLengthOfLCIS(nums) == 0);
    }
    return 0;
}
