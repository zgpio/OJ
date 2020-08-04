#include <lc/bt.h>
#include <iostream>
using namespace std;

class Solution
{
   public:
    TreeNode *invertTree(TreeNode *root)
    {
        helper(root);
        return root;
    }

   private:
    void helper(TreeNode *root)
    {
        if (root) {
            swap(root->left, root->right);
            helper(root->left);
            helper(root->right);
        }
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    TreeNode *t = constructT("[4,2,7,1,3,6,9]");
    s.invertTree(t);
    inorder(t);

    return 0;
}
