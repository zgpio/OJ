#ifndef BT_H
#define BT_H
#include <vector>
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *constructT(std::string a);
void preorder(TreeNode *t);
void inorder(TreeNode *t);

#endif /* ifndef BT_H */
