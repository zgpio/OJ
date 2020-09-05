#include <bits/stdc++.h>
#include "lc/bt.h"
using namespace std;

class Solution
{
   public:
    void flatten(TreeNode* root)
    {
        if (root) {
            flatten(root->left);
            flatten(root->right);
            auto p = root->left;
            if (p) {
                while (p->right)
                    p = p->right;
                p->right = root->right;
                root->right = root->left;
                root->left = nullptr;
            }
        }
    }
};

int main(int argc, char* argv[])
{
    auto t = constructT("(1, 2, 5, 3, 4, null, 6)");
    Solution s;
    s.flatten(t);
    inorder(t);
    return 0;
}
