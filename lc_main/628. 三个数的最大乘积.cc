#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <cassert>
using namespace std;
class Solution
{
   public:
    // 两种情况: 1) 2个最小负数和1个最大正数; 2) 三个最大正数.
    int maximumProduct(vector<int>& nums)
    {
        int min1 = INT_MAX, min2 = INT_MAX;
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        for (int n : nums) {
            if (n <= min1) {
                min2 = min1;
                min1 = n;
            } else if (n <= min2) {  // n lies between min1 and min2
                min2 = n;
            }
            if (n >= max1) {  // n is greater than max1, max2 and max3
                max3 = max2;
                max2 = max1;
                max1 = n;
            } else if (n >= max2) {  // n lies betweeen max1 and max2
                max3 = max2;
                max2 = n;
            } else if (n >= max3) {  // n lies betwen max2 and max3
                max3 = n;
            }
        }
        return max(min1 * min2 * max1, max1 * max2 * max3);
    }
};
int main(int argc, char* argv[])
{
    Solution s;
    vector<int> nums{1, 2, 3, 4};
    assert(s.maximumProduct(nums) == 24);
    return 0;
}
