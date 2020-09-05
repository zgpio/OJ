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
    int dfs(vector<string>& arr, int childIndex, int m)
    {
        if (childIndex == arr.size()) {
            return 0;
        }
        int t = m;
        if (isUnique(arr[childIndex], t)) {
            int curLen = arr[childIndex].length();
            int len1 = curLen + dfs(arr, childIndex + 1, t);
            int len2 = dfs(arr, childIndex + 1, m);
            return max(len1, len2);
        }
        return dfs(arr, childIndex + 1, m);
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
