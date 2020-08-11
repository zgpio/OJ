#include <bits/stdc++.h>
using namespace std;

// 题意: 对栈进行排序, 栈顶放大的元素, 而且限定了只能用一个辅助栈.
// 思路: 先取出给定栈的栈顶元素存入一个临时变量v中, 然后将辅助栈的栈顶大于v的元素弹回给定栈, 再将v压入辅助栈,
//       重复以上操作直至给定栈取空, 这时候辅助栈就是排序完成的结果, 返回即可.

class Solution
{
   public:
    stack<int> sort(stack<int> s)
    {
        stack<int> res;
        while (!s.empty()) {
            int v = s.top();
            s.pop();
            while (!res.empty() && res.top() > v) {
                s.push(res.top());
                res.pop();
            }
            res.push(v);
        }
        return res;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    assert(s.sort(stack<int>({4, 2, 1, 3, 5})) == stack<int>({1, 2, 3, 4, 5}));
    return 0;
}
