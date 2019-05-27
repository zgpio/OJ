#include <assert.h>
#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
#include <initializer_list>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <string>
#include <tuple>
#include <unordered_map>
using namespace std;

// ref to https://blog.csdn.net/qq_35280514/article/details/51637920
// 用来终止递归并打印最后一个元素的函数
// 此函数必须在可变参数版本的print定义之前声明
template <typename T>
void print(const T &t)
{
    cout << t << endl;  // 参数包中最后一个元素
}
// 包中除最后一个元素之外的其他元素都会调用这个版本的pirnt
template <typename T, typename... Args>
void print(const T &t, const Args &... rest)
{
    cout << t << ", ";  // 打印第一个实参, 包中元素减1
    print(rest...);  // 递归调用, 打印剩余实参, ...表示展开rest参数包
}

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> res;
        if (n == 0) return res;
        // sort the input vector in ascending order
        sort(nums.begin(), nums.end());
        // optimization check: no solution
        if (nums.front() > 0 || nums.back() < 0) return res;

        for (int i = 0; i < n - 2; ++i) {
            // optimiaztion check: no need to continue the loop
            if (nums[i] > 0) break;
            // move fixed number index to skip the repeated values
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1, k = n - 1; j < k;) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    // find possible solution
                    // print(nums[i], nums[j], nums[k]);
                    res.push_back({nums[i], nums[j], nums[k]});
                    // move both left and right indexes
                    ++j;
                    --k;
                    // move left index to skip the repeated values
                    while (j < k && nums[j] == nums[j - 1]) ++j;
                    // move right index to skip the repeated values
                    while (j < k && nums[k] == nums[k + 1]) --k;
                }
                else if (sum < 0) {
                    // move left index to increase sum
                    ++j;
                }
                else {
                    // move right index to decrease sum
                    --k;
                }
            }
        }

        return res;
    }
};

int main()
{
    Solution sol;

    vector<int> t1{-1, 0, 1, 2, -1, -4};
    vector<vector<int>> a1{{-1, 0, 1}, {-1, -1, 2}};

    assert(sol.threeSum(t1) == a1);

    return 0;
}
