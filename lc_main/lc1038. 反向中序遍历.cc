#include <lc/bt.h>
#include <iostream>

class Solution
{
    int sum = 0;

   public:
    TreeNode* bstToGst(TreeNode* root)
    {
        sum = 0;
        helper(root);
        return root;
    }
    void helper(TreeNode* root)
    {
        if (root) {
            helper(root->right);
            sum += root->val;
            root->val = sum;
            helper(root->left);
        }
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    TreeNode* t = constructT("[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]");
    s.bstToGst(t);
    inorder(t);
    return 0;
}
