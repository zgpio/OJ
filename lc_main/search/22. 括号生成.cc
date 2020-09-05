#include <bits/stdc++.h>
using namespace std;

class Solution
{
   public:
    vector<string> generateParenthesis(int n)
    {
        m_ans.clear();
        helper(n, n);
        return m_ans;
    }

   private:
    void helper(int lc, int rc)  // 手中的左右括号数目
    {
        if (lc == 0 && rc == 0) {
            m_ans.push_back(m_str);
            return;
        }
        if (rc > lc) {
            m_str.push_back(')');
            helper(lc, rc - 1);
            m_str.pop_back();
        }
        if (lc > 0) {
            m_str.push_back('(');
            helper(lc - 1, rc);
            m_str.pop_back();
        }
    }
    vector<string> m_ans;
    string m_str;
};

int main(int argc, char *argv[])
{
    Solution s;
    auto a = s.generateParenthesis(3);

    assert(a == (vector<string>{"()()()", "()(())", "(())()", "(()())", "((()))"}));

    return 0;
}
