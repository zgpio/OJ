#include <lc/bt.h>
#include <iostream>
#include <queue>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
   public:
    int widthOfBinaryTree(TreeNode *root)
    {
        // pair<root, pos> pos是完全二叉树在数组中的位置
        queue<pair<TreeNode *, uint_fast64_t>> q;
        q.push({root, 0});
        int i = 0;
        int N = 1;
        int rv = 1;
        while (!q.empty()) {
            auto t = q.front();  // 使用auto&导致错误: pop后引用失效
            q.pop();
            i++;
            if (t.first->left) {
                q.push({t.first->left, t.second * 2 + 1});
            }
            if (t.first->right) {
                q.push({t.first->right, t.second * 2 + 2});
            }
            if (i == N && !q.empty()) {
                auto f = q.front();
                auto b = q.back();
                int w = b.second - f.second + 1;
                if (rv < w)
                    rv = w;
                N = q.size();
                i = 0;
            }
        }
        return rv;
    }
};
int main(int argc, char *argv[])
{
    //
    //           1
    //         /   \
    //        3     2
    //       / \     \
    //      5   3     9
    //

    Solution s;
    {
        TreeNode *t = constructT("(1,3,2,5,3,null,9)");
        inorder(t);
        assert(s.widthOfBinaryTree(t) == 4);
    }
    {
        TreeNode *t = constructT("[1]");
        inorder(t);
        assert(s.widthOfBinaryTree(t) == 1);
    }
    return 0;
}
