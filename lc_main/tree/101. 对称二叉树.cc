#include <iostream>
#include <lc/bt.h>
using namespace std;

class Solution {
    bool check(TreeNode *p, TreeNode *q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
    }
public:

    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
};
int main(int argc, char *argv[])
{
    Solution s;
    TreeNode *t = constructT("[1,2,2,3,4,4,3]");
    s.isSymmetric(t);
    return 0;
}
