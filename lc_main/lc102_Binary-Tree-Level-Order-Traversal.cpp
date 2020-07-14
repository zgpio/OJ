#include "lc/bt.h"
#include "lc/lc.h"
using namespace std;

// Runtime: 8 ms, faster than 71.73% of C++ online submissions for Binary Tree
// Level Order Traversal. Memory Usage: 13.5 MB, less than 99.84% of C++ online
// submissions for Binary Tree Level Order Traversal.
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        queue<TreeNode *> q;
        if (root) q.push(root);
        int n = 1;
        vector<vector<int>> ans;
        while (!q.empty()) {
            int cnt = 0;
            vector<int> layer;
            while (n--) {
                TreeNode *t = q.front();
                q.pop();
                if (t->left) {
                    q.push(t->left);
                    cnt++;
                }
                if (t->right) {
                    q.push(t->right);
                    cnt++;
                }
                layer.push_back(t->val);
            }
            n = cnt;
            ans.push_back(layer);
        }
        for (auto i : ans) {
            for (auto j : i)
                std::cout << j << " ";
            std::cout << std::endl;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> a1 = {{3}, {9, 20}, {15, 7}};
    TreeNode *t1 = constructT("[3, 9, 20, null, null, 15, 7]");
    assert(sol.levelOrder(t1) == a1);

    vector<vector<int>> a2 = {};
    TreeNode *t2 = constructT("[]");
    assert(sol.levelOrder(t2) == a2);
    return 0;
}
