#include <bits/stdc++.h>
using namespace std;

class Solution
{
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        // NOTE vector<int> 是可以直接比较的
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        for (auto i : intervals) {
            if (ans.empty())
                ans.push_back(i);
            else {
                if (ans.back()[1] < i[0])
                    ans.push_back(i);
                else {
                    ans.back()[1] = max(ans.back()[1], i[1]);
                }
            }
        }

        for (auto i : ans) {
            std::cout << "(" << i[0] << "," << i[1] << ")";
            std::cout << "-";
        }
        std::cout << std::endl;
        return ans;
    }
};

int main()
{
    Solution sol;

    // 验证vector<int>可以比较大小
    assert((vector<int>{1, 4}) < (vector<int>{1, 5}));
    assert((vector<int>{1, 4}) < (vector<int>{2, 4}));
    vector<vector<int>> t1 = {{1, 4}, {4, 5}};
    vector<vector<int>> a1 = {{1, 5}};
    vector<vector<int>> t2 = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> a2 = {{1, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> t3 = {};
    vector<vector<int>> a3 = {};

    vector<vector<int>> t4 = {{1, 4}, {2, 3}};
    vector<vector<int>> a4 = {{1, 4}};
    vector<vector<int>> t5 = {{2, 6}, {1, 3}, {8, 10}, {15, 18}};
    vector<vector<int>> a5 = {{1, 6}, {8, 10}, {15, 18}};

    assert(sol.merge(t1) == a1);
    assert(sol.merge(t2) == a2);
    assert(sol.merge(t3) == a3);
    assert(sol.merge(t4) == a4);
    assert(sol.merge(t5) == a5);

    return 0;
}
