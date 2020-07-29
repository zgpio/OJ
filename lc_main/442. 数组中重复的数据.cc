#include <iostream>
#include <vector>
using namespace std;

class Solution
{
   public:
    // 不要求结果有序
    vector<int> findDuplicates(vector<int>& nums)
    {
        vector<int> rv;
        for (int i = 0; i < nums.size(); i++) {
            while (nums[nums[i] - 1] != nums[i]) {  // 如果第nums[i]-1个抽屉中存放的不是nums[i], 就交换过去
                swap(nums[nums[i] - 1], nums[i]);
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] - 1 != i)
                rv.push_back(nums[i]);
        }
        return rv;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    vector<int> v{4, 3, 2, 7, 8, 2, 3, 1};
    assert(s.findDuplicates(v) == (vector<int>{3, 2}));
    return 0;
}
