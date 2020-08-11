#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target)
    {
        int p = lower_bound(nums, target);
        if (p >= nums.size() || nums[p] != target) return 0;
        int i;
        for (i = p; i < nums.size(); i++) {
            if (nums[i] != target) break;
        }
        return i - p;
    }

private:
    //返回target在有序向量A中出现的第一个位置
    //如果target不在A中，则是target应该插入的位置
    int lower_bound(vector<int> &A, int target)
    {
        int l = 0, r = A.size();

        while (l < r) {
            int mid = l + (r - l) / 2;
            if (target == A[mid]) {
                r = mid;
            }
            else if (target > A[mid]) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }

        return l;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    {
        vector<int> nums = {5, 7, 7, 8, 8, 10};
        assert(sol.search(nums, 8) == 2);
    }
    {
        vector<int> nums = {2, 2};
        assert(sol.search(nums, 3) == 0);
    }
    {
        vector<int> nums = {};
        assert(sol.search(nums, 0) == 0);
    }
    return 0;
}
