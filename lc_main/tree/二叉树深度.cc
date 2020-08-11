#include "lc/bt.h"
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxDepth(TreeNode *root)
    {
        if (root == NULL) return 0;
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        return max(l, r) + 1;
    }
};

int main(int argc, char *argv[])
{
    //    3
    //   / \
    //  9  20
    //    /  \
    //   15   7

    Solution s;
    TreeNode *t = constructT("[3, 9, 20, -1, -1, 15, 7]");
    assert(s.maxDepth(t) == 3);

    return 0;
}
