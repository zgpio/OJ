#include <iostream>
#include <vector>
using namespace std;

class Solution
{
   public:
    int findKthLargest(vector<int>& nums, int k)
    {
        const int n = nums.size();
        return helper(nums, 0, n - 1, k - 1);
    }

   private:
    // [l, r]
    int helper(vector<int>& nums, int l, int r, int k)
    {
        int pivot = nums[l];
        int i = l, j = r;
        while (i < j) {
            while (i < j && nums[j] < pivot)
                j--;
            nums[i] = nums[j];
            while (i < j && nums[i] >= pivot)
                i++;
            nums[j] = nums[i];
        }
        nums[i] = pivot;
        if (i == k)
            return pivot;
        else if (i < k)
            return helper(nums, i + 1, r, k);
        else
            return helper(nums, l, i - 1, k);
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    vector<int> nums{3, 2, 1, 5, 6, 4};
    int pred = s.findKthLargest(nums, 2);
    assert(pred == 5);
    return 0;
}
