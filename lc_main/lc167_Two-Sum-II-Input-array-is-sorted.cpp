#include "lc/lc.h"
using namespace std;


// Runtime: 8 ms, faster than 62.49% of C++ online submissions for Two Sum II - Input array is sorted.
// Memory Usage: 9.5 MB, less than 68.70% of C++ online submissions for Two Sum II - Input array is sorted.
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int n = numbers.size();
        int i = 0, j = n - 1;
        vector<int> ans;
        while (i < j) {
            int sum = numbers[i] + numbers[j];
            if (sum == target) {
                ans.push_back(i + 1);
                ans.push_back(j + 1);
                break;
            }
            else if (sum < target) {
                ++i;
            }
            else {
                --j;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> a1{2, 7, 11, 15};
    vector<int> ans1{1, 2};
    assert(sol.twoSum(a1, 9) == ans1);

    return 0;
}
