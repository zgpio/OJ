#include <algorithm>
#include <cassert>
#include <climits>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <string>
#include <tuple>
#include <unordered_map>
using namespace std;

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    vector<int> a;

public:
    bool isValidBST(TreeNode *root)
    {
        if (!root) return true;
        inorder(root);
        int L = a.size();
        for (int i = 0; i + 1 < L; ++i) {
            if (a[i] >= a[i + 1]) return false;
        }
        return true;
    }
    void inorder(TreeNode *root)
    {
        if (root) {
            inorder(root->left);
            a.push_back(root->val);
            inorder(root->right);
        }
    }
};

TreeNode *constructT(vector<int> a)
{
    std::deque<TreeNode *> q;
    TreeNode *T = new TreeNode(a[0]);
    q.push_back(T);
    int L = a.size();
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

void preorder(TreeNode *t);
void inorder(TreeNode *t);
int main()
{
    Solution sol;
    vector<int> a = {5, 1, 4, -1, -1, 3, 6};
    TreeNode *ta = constructT(a);
    vector<int> a2 = {1, 1};
    TreeNode *ta2 = constructT(a2);
    vector<int> a3 = {10, 5, 15, -1, -1, 6, 20};
    TreeNode *ta3 = constructT(a3);
    preorder(ta3);
    std::cout << std::endl;
    inorder(ta3);
    std::cout << std::endl;

    TreeNode *nul = nullptr;
    assert(sol.isValidBST(ta) == false);
    assert(sol.isValidBST(ta2) == false);
    assert(sol.isValidBST(ta3) == false);
    assert(sol.isValidBST(nul) == true);
    return 0;
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
