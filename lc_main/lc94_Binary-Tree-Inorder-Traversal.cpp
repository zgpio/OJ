#include "lc/bt.h"
#include "lc/lc.h"
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
    vector<int> a1 = {1, -1, 2, 3};
    TreeNode *t1 = constructT(a1);
    vector<int> ans1 = {1, 3, 2};
    assert(sol.inorderTraversal(t1) == ans1);
    assert(sol.inorderTraversal(t1) == ans1);

    return 0;
}
