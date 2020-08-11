#include <bits/stdc++.h>
using namespace std;

class Solution
{
   public:
    string multiply(string num1, string num2)
    {
        // 每一位相乘结果在res[i+1] res[i+j+1]这两位里 累加即可
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        int size1 = num1.length(), size2 = num2.length();
        vector<int> memo(size1 + size2, 0);
        string res = "";
        for (int i = size1 - 1; i >= 0; i--) {
            int n1 = num1[i] - '0';
            for (int j = size2 - 1; j >= 0; j--) {
                int n2 = num2[j] - '0';
                int tempSum = memo[i + j + 1] + n1 * n2;
                memo[i + j + 1] = tempSum % 10;
                memo[i + j] += tempSum / 10;
            }
        }
        bool flag = true;
        for (int i = 0; i < memo.size(); i++) {
            if (memo[i] != 0 || !flag) {
                flag = false;
                res.push_back(memo[i] + '0');
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    assert(sol.multiply("123", "2") == "246");

    return 0;
}
