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
    vector<pair<string, int>> cases = {
        {"[3, 9, 20, null, null, 15, 7]", 3},
        {"[]", 0},
        {"[1]", 1}
    };
    assert(constructT("[]") == NULL);
    for (auto c : cases) {
        TreeNode *t1 = constructT(c.first);
        assert(sol.maxDepth(t1) == c.second);
    }

    return 0;
}
