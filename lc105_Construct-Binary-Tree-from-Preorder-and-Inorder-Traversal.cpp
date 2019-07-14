#include "lc/bt.h"
#include "lc/lc.h"
using namespace std;

// TODO: 不适用于树中存在重复元素
class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return work(preorder, inorder, 0, preorder.size() - 1, 0,
                    inorder.size() - 1);
    }

private:
    // preorder[lp, rp]代表了当前子树的前序遍历
    // inorder[li, ri]代表了当前子树的中序遍历
    TreeNode *work(vector<int> &preorder, vector<int> &inorder, int lp, int rp,
                   int li, int ri)
    {
        // 判断长度为0的情况
        if (lp > rp) return NULL;
        // 创建根节点
        TreeNode *root = new TreeNode(preorder[lp]);
        // 找到根节点在inorder中的位置
        for (int k = li; k <= ri; k++) {
            if (preorder[lp] == inorder[k]) {
                // 分治处理两棵子树
                root->left =
                    work(preorder, inorder, lp + 1, lp + (k - li), li, k - 1);
                root->right =
                    work(preorder, inorder, lp + (k - li) + 1, rp, k + 1, ri);
            }
        }
        return root;
    }
};

int main()
{
    Solution sol;
    vector<int> pre1 = {3, 9, 20, 15, 7};
    vector<int> in1 = {9, 3, 15, 20, 7};
    TreeNode *t1 = sol.buildTree(pre1, in1);
    preorder(t1);
    std::cout << std::endl;
    inorder(t1);

    return 0;
}
