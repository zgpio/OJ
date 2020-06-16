#include "lc/lc.h"
#include "lc/bt.h"
using namespace std;


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
