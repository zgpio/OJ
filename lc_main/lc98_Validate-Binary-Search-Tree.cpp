#include "lc/bt.h"
#include "lc/lc.h"
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
    assert(sol.isValidBST(nullptr) == true);
    vector<pair<string, bool>> cases = {
        {"[5, 1, 4, null, null, 3, 6]", false},
        {"[1, 1]", false},
        {"[10, 5, 15, null, null, 6, 20]", false},
        {"[]", true}
    };
    for (auto c : cases) {
        TreeNode *ta = constructT(c.first);
        preorder(ta);
        std::cout << std::endl;
        inorder(ta);
        assert(sol.isValidBST(ta) == c.second);
    }

    return 0;
}
