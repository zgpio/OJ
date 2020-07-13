#include "bt.h"
#include <queue>
#include <iostream>

// -1 表示 null
TreeNode *constructT(std::vector<int> a)
{
    int L = a.size();
    if (L == 0) return nullptr;
    std::queue<TreeNode *> q;
    TreeNode *T = new TreeNode(a[0]);
    q.push(T);
    for (int i = 0; i * 2 + 1 < L; ++i) {
        TreeNode *t = q.front();
        q.pop();

        if (a[i * 2 + 1] != -1) {
            t->left = new TreeNode(a[i * 2 + 1]);
            q.push(t->left);
        }
        if (i * 2 + 2 < L && a[i * 2 + 2] != -1) {
            t->right = new TreeNode(a[i * 2 + 2]);
            q.push(t->right);
        }
    }
    return T;
}

void preorder(TreeNode *t)
{
    if (t) {
        std::cout << t->val << " ";
        preorder(t->left);
        preorder(t->right);
    }
}
static void inorder_(TreeNode *t)
{
    if (t != NULL) {
        inorder_(t->left);
        std::cout << t->val << " ";
        inorder_(t->right);
    }
}
void inorder(TreeNode *t)
{
    inorder_(t);
    std::cout << std::endl;
}
