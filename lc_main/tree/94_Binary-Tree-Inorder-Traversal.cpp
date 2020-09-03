#include "lc/bt.h"
#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> a;

public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        a.clear();
        inorder(root);
        return a;
    }
    void inorder(TreeNode *p)
    {
        if (p) {
            inorder(p->left);
            a.push_back(p->val);
            inorder(p->right);
        }
    }
};

int main()
{
    Solution sol;
    TreeNode *t1 = constructT("[1, null, 2, 3]");
    vector<int> ans1 = {1, 3, 2};
    assert(sol.inorderTraversal(t1) == ans1);

    return 0;
}
