#include "lc/bt.h"
#include <iostream>
#include <stack>
using namespace std;

// 中序遍历二叉搜索树可得到一个关键字的有序序列, 由小到大排序.
// 用自定义栈模拟深度优先遍历, 先序、中序、后序遍历都属于深度优先.
class Solution {
public:
    bool isValidBST(TreeNode *root)
    {
        stack<TreeNode *> stack;
        long long pre = LLONG_MIN;

        while (!stack.empty() || root != nullptr) {
            while (root != nullptr) {
                stack.push(root);
                root = root->left;
            }
            root = stack.top();
            stack.pop();
            // 如果中序遍历访问的节点的值小于等于前一个元素, 说明不是二叉搜索树
            if (root->val <= pre) return false;
            pre = root->val;
            root = root->right;
        }
        return true;
    }
};

// lc144. 二叉树的前序遍历
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> rv;
    stack<TreeNode *> s;
    while (!s.empty() || root) {
        while (root) {
            rv.push_back(root->val); // 先序遍历
            s.push(root);
            root = root->left;
        }

        root = s.top();
        s.pop();
        root = root->right;
    }
    return rv;
}

int main(int argc, char *argv[])
{
    vector<pair<initializer_list<int>, bool>> cases = {
        {{1, 2, 3, 4, 5, 6}, false},
        {{5, 1, 4, -1, -1, 3, 6}, false},
        {{1, 1}, false},
        {{1, -1, 1}, false},
        {{10, 5, 15, -1, -1, 6, 20}, false}};
    Solution s;
    for (auto i : cases) {
        TreeNode *t = constructT(i.first);
        for (auto x:preorderTraversal(t)) {
            cout << x << " ";
        }
        cout << endl;
        assert(s.isValidBST(t) == i.second);
    }
    return 0;
}
