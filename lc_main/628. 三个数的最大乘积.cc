#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution
{
   public:
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
    // 只是为了展示大小顶堆的使用
    int maximumProduct2(vector<int>& nums)
    {
        priority_queue<int> maxh;                             // 大顶堆保存最小的两个数
        priority_queue<int, vector<int>, greater<int>> minh;  // 小顶堆保存最大的三个数
        for (auto i : nums) {
            if (maxh.size() < 2)
                maxh.push(i);
            else {
                if (i < maxh.top()) {
                    maxh.pop();
                    maxh.push(i);
                }
            }
            if (minh.size() < 3)
                minh.push(i);
            else {
                if (i > minh.top()) {
                    minh.pop();
                    minh.push(i);
                }
            }
        }
        int min1 = maxh.top(); maxh.pop();
        int min2 = maxh.top(); maxh.pop();
        int max1 = minh.top(); minh.pop();
        int max2 = minh.top(); minh.pop();
        int max3 = minh.top(); minh.pop();
        return max(min1 * min2 * max3, max1 * max2 * max3);
    }
};
int main(int argc, char* argv[])
{
    Solution s;
    vector<int> nums{1, 2, 3, 4};
    assert(s.maximumProduct(nums) == 24);
    assert(s.maximumProduct2(nums) == 24);
    return 0;
}
