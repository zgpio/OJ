#include "lc/lc.h"
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] == target) {
                return m;
            }

            if (nums[l] > nums[r]) {
                if (nums[m] > nums[r]) {
                    if (nums[l] <= target && target <= nums[m]) {
                        r = m - 1;
                    }
                    else if (target < nums[l] || target > nums[m]) {
                        l = m + 1;
                    }
                }
                else {
                    if (nums[m] <= target && target <= nums[r]) {
                        l = m + 1;
                    }
                    else if (target < nums[m] || target > nums[r]) {
                        r = m - 1;
                    }
                }
            }
            else {
                if (target < nums[m])
                    r = m - 1;
                else
                    l = m + 1;
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
    std::cout << "end" << std::endl;
    return 0;
}
