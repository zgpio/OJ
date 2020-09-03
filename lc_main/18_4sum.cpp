#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n - 3; ++i) {
            for (int j = i + 1; j < n - 2; ++j) {
                int obj = target - nums[i] - nums[j];
                int l = j + 1;
                int r = n - 1;
                while (l < r) {
                    if (nums[l] + nums[r] == obj) {
                        ans.push_back(
                            vector<int>{nums[i], nums[j], nums[l], nums[r]});
                        l++, r--;
                    }
                    else if (nums[l] + nums[r] < obj)
                        l++;
                    else
                        r--;
                }
            }
        }
        // vector 元素去重
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        for (auto i : ans) {
            for (auto j : i)
                std::cout << j << " ";
            std::cout << std::endl;
        }
        std::cout << std::endl;
        return ans;
    }
};

void testAns(vector<vector<int>> a, vector<vector<int>> b)
{
    sort(a.begin(), a.end());
    for (auto &i : a)
        sort(i.begin(), i.end());

    sort(b.begin(), b.end());
    for (auto &i : b)
        sort(i.begin(), i.end());
    assert(a == b);
}

int main()
{
    Solution sol;

    vector<int> t1 = {-2, 1, 0, -1, 0, -2, 2};
    vector<vector<int>> a1 = {{-1, 0, 0, 1}, {-2, -1, 1, 2}, {-2, 0, 0, 2}};
    vector<vector<int>> p1 = sol.fourSum(t1, 0);
    testAns(p1, a1);
    vector<int> t2 = {-3, -2, -1, 0, 0, 1, 2, 3};
    vector<vector<int>> a2 = {{-3, -2, 2, 3}, {-3, -1, 1, 3}, {-3, 0, 0, 3},
                              {-3, 0, 1, 2},  {-2, -1, 0, 3}, {-2, -1, 1, 2},
                              {-2, 0, 0, 2},  {-1, 0, 0, 1}};
    vector<vector<int>> p2 = sol.fourSum(t2, 0);
    testAns(p2, a2);
    return 0;
}
