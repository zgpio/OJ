#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution
{
   public:
    // 前提条件: 数组中不存在重复元素
    int findMin(vector<int>& nums)
    {
        // 如果序列只有一个元素, 返回这个元素
        if (nums.size() == 1) {
            return nums[0];
        }

        int left = 0, right = nums.size() - 1;

        // 如果末尾元素大于首元素, 说明序列没有旋转
        if (nums[right] > nums[0]) {
            return nums[0];
        }

        // 二分查找临界点
        while (right >= left) {
            int mid = left + (right - left) / 2;

            // 临界点: 从最高到最低
            if (nums[mid] > nums[mid + 1]) {
                return nums[mid + 1];
            }
            if (nums[mid - 1] > nums[mid]) {
                return nums[mid];
            }

            // 如果mid处于左半部分
            if (nums[mid] > nums[0]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    vector<int> v{3, 4, 5, 1, 2};
    assert(s.findMin(v) == 1);
    return 0;
}
