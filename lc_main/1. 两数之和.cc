#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
   public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> m;
        vector<int> rv;
        for (int i = 0; i < nums.size(); i++) {
            int j = target - nums[i];
            auto got = m.find(j);
            if (got != m.end()) {
                rv.push_back(got->second);
                rv.push_back(i);
                return rv;
            }
            m[nums[i]] = i;
        }
        return rv;
    }
};
int main(int argc, char* argv[])
{
    Solution s;
    vector<int> nums{2, 7, 11, 15};
    assert(s.twoSum(nums, 9) == (vector<int>{0, 1}));
    return 0;
}
