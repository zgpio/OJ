#include <iostream>
#include "lc/bt.h"
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root==nullptr)
            return nullptr;
        if (root==p || root==q)
            return root;

        TreeNode * l = lowestCommonAncestor(root->left, p, q);
        TreeNode * r = lowestCommonAncestor(root->right, p, q);
        if (l==nullptr)
            return r;
        else if (r==nullptr)
            return l;
        else if (l!=nullptr && r!=nullptr)
            return root;
        return nullptr;
    }

};

int main(int argc, char *argv[])
{
    Solution s;
    {
        //           3
        //        /     \
        //       5       1
        //      / \     / \
        //     6   2   0   8
        //        / \
        //       7   4
        TreeNode * t = constructT("[3,5,1,6,2,0,8,-1,-1,7,4]");
        inorder(t);
        // 5 1 -> 3
        assert(s.lowestCommonAncestor(t, t->left, t->right)==t);
        // 5 4 -> 5
        assert(s.lowestCommonAncestor(t, t->left, t->left->right->right)==t->left);
    }
    return 0;
}
