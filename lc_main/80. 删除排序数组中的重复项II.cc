#include <bits/stdc++.h>
using namespace std;

class Solution
{
   public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() < 3)
            return nums.size();

        int i = 0;
        int p = 0;
        nums.push_back(nums.back() + 1);  // 哨兵
        for (int j = 1; j < nums.size(); j++) {
            if (nums[i] != nums[j]) {
                if (j - i > 1) {
                    nums[p++] = nums[i];
                    nums[p++] = nums[i];
                } else {
                    nums[p++] = nums[i];
                }
                i = j;
            }
        }
        nums.resize(p);

        for (auto i : nums)
            cout << i << " ";
        cout << endl;
        return nums.size();
    }
};

int main()
{
    Solution sol;

    {
        vector<int> t = {1, 1, 1, 2, 2, 3};
        vector<int> a = {1, 1, 2, 2, 3};
        assert(sol.removeDuplicates(t) == 5);
        assert(t == a);
    }
    {
        vector<int> t = {0, 0, 1, 1, 1, 1, 2, 3, 3};
        vector<int> a = {0, 0, 1, 1, 2, 3, 3};
        assert(sol.removeDuplicates(t) == 7);
        assert(t == a);
    }
    {
        vector<int> t = {1, 1, 1};
        vector<int> a = {1, 1};
        assert(sol.removeDuplicates(t) == 2);
        assert(t == a);
    }
    {
        vector<int> t = {};
        vector<int> a = {};
        assert(sol.removeDuplicates(t) == 0);
        assert(t == a);
    }

    return 0;
}
