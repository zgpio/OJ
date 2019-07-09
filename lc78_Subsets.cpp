#include "lc/lc.h"
using namespace std;

// TODO: 组合数生成测试
// c(r,n)
// k1为当前已记录序列长度, k2为剩余待选取元素的起始位置
vector<vector<int>> ret;
int cnt;
void combination_recursive(vector<int> &rec, const int arr[], int n, int r,
                           int k1, int k2)
{
    cnt++;
    if (k1 == r) // 输出当前序列
    {
        // for (int i = 0; i < r; ++i)
        //     cout << rec[i] << " ";
        // cout << endl;
        ret.push_back(rec);
    }
    else
        for (int i = k2; i + r - k1 - 1 < n; ++i) {
            rec[k1] = arr[i]; // 子序列赋值
            combination_recursive(rec, arr, n, r, k1 + 1, i + 1); // 递归回溯
        }
}
void combination(int arr[], int n) // 输出n个元素的全部组合
{
    for (int i = 0; i <= n; ++i) {
        vector<int> rec(i); // 记录组合序列
        combination_recursive(rec, arr, n, i, 0, 0);
    }
}

class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int n = nums.size();
        int *a = new int[n];
        ret.clear();
        for (int i = 0; i < n; ++i) {
            a[i] = nums[i];
        }
        combination(a, n);
        delete [] a;
        return ret;
    }
};

int main()
{
    // int a[] = {0, 1, 2, 3, 4, 5, 6};
    // int len = sizeof(a) / sizeof(a[0]);
    // combination(a, len);

    Solution sol;
    vector<int> t1 = {1, 2, 3};
    auto ret = sol.subsets(t1);
    std::cout << cnt << std::endl;
    for (auto i : ret) {
        for (auto j : i) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
