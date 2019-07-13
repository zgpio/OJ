#include "lc/bt.h"
#include "lc/lc.h"
using namespace std;

// Runtime: 16 ms, faster than 46.67% of C++ online submissions for Maximum
// Depth of Binary Tree. Memory Usage: 19.1 MB, less than 91.60% of C++ online
// submissions for Maximum Depth of Binary Tree.
class Solution {
    int depth;

public:
    int maxDepth(TreeNode *root)
    {
        depth = 0;
        dfs(root, 0);
        return depth;
    }
    void dfs(TreeNode *p, int d)
    {
        if (!p) {
            if (depth < d) depth = d;
            return;
        }
        dfs(p->left, d + 1);
        dfs(p->right, d + 1);
    }
};

int main()
{
    Solution sol;
    vector<int> v1 = {3, 9, 20, -1, -1, 15, 7};
    TreeNode *t1 = constructT(v1);
    assert(sol.maxDepth(t1) == 3);

    vector<int> v2 = {};
    TreeNode *t2 = constructT(v2);
    assert(sol.maxDepth(t2) == 0);

    vector<int> v3 = {1};
    TreeNode *t3 = constructT(v3);
    assert(sol.maxDepth(t3) == 1);
    return 0;
}
