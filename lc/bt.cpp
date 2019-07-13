#include "bt.h"
#include <deque>
#include <iostream>
using namespace std;

TreeNode *constructT(vector<int> a)
{
    int L = a.size();
    if (L == 0) return nullptr;
    std::deque<TreeNode *> q;
    TreeNode *T = new TreeNode(a[0]);
    q.push_back(T);
    for (int i = 0; i * 2 + 1 < L; ++i) {
        TreeNode *t = q.front();
        q.pop_front();

        if (a[i * 2 + 1] != -1) {
            t->left = new TreeNode(a[i * 2 + 1]);
            q.push_back(t->left);
        }
        if (i * 2 + 2 < L && a[i * 2 + 2] != -1) {
            t->right = new TreeNode(a[i * 2 + 2]);
            q.push_back(t->right);
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
void inorder(TreeNode *t)
{
    if (t != NULL) {
        inorder(t->left);
        std::cout << t->val << " ";
        inorder(t->right);
    }
}
