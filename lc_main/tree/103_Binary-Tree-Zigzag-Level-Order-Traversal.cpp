#include "lc/bt.h"
#include <bits/stdc++.h>
using namespace std;

// Runtime: 4 ms, faster than 90.83% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.
// Memory Usage: 13.6 MB, less than 34.85% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        deque<TreeNode *> q;
        if (root) q.push_back(root);
        int n = 1;
        int dir = 1;
        vector<vector<int>> ans;
        while (!q.empty()) {
            int cnt = 0;
            vector<int> layer;
            while (n--) {
                TreeNode *t;
                t = q.front();
                q.pop_front();
                if (t->left) {
                    q.push_back(t->left);
                    cnt++;
                }
                if (t->right) {
                    q.push_back(t->right);
                    cnt++;
                }
                if (dir) {
                    layer.push_back(t->val);
                }
                else {
                    layer.insert(layer.begin(), t->val);
                }
            }
            n = cnt;
            dir = !dir;
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

    TreeNode *t1 = constructT("[3, 9, 20, null, null, 15, 7]");

    vector<vector<int>> a1 = {{3}, {20, 9}, {15, 7}};
    assert(sol.zigzagLevelOrder(t1) == a1);

    TreeNode *t2 = constructT("[]");
    assert(t2 == nullptr);

    vector<vector<int>> a2 = {};
    assert(sol.zigzagLevelOrder(t2) == a2);
    return 0;
}
