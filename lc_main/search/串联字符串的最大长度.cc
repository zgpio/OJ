#include <bits/stdc++.h>
using namespace std;

class Solution
{
   public:
    int maxLength(vector<string>& arr)
    {
        // 当作哈希状态表，记录每个小写字母出现的次数
        int m = 0;
        return dfs(arr, 0, m);
    }

   private:
    // 解空间树是二叉树, 每个元素只有0或1两种选择
    int dfs(vector<string>& arr, int level, const int m)
    {
        if (level == arr.size()) {
            return 0;
        }
        int t = m;
        if (isUnique(arr[level], t)) {
            int len0 = dfs(arr, level + 1, m);
            int len1 = arr[level].length() + dfs(arr, level + 1, t);
            return max(len1, len0);
        }
        return dfs(arr, level + 1, m);
    }
    bool isUnique(string& s, int& t)
    {
        for (char c : s) {
            int i = c - 'a';
            if (t & (1 << i)) {
                return false;
            }
            t |= (1 << i);
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<string> a{"un", "iq", "ue"};
    assert(s.maxLength(a) == 4);
    return 0;
}
