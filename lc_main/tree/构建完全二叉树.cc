#include <lc/bt.h>
#include <iostream>
using namespace std;

// 从数组构建完全二叉树
vector<TreeNode> createBinTree(vector<int> &a)
{
    vector<TreeNode> nodeList(a.size());
    // 把数组中的值赋值到树结点中
    for (int i = 0; i < a.size(); i++) {
        nodeList[i].val = a[i];
    }
    for (int j = 0; j < a.size() / 2 - 1; j++) {
        nodeList[j].left = &nodeList[j * 2 + 1];
        nodeList[j].right = &nodeList[j * 2 + 2];
    }

    // 最后一个父结点, 可能没有右孩子
    int lastParent = a.size() / 2 - 1;
    // 所以, 先处理左孩子
    nodeList[lastParent].left = &nodeList[lastParent * 2 + 1];
    // 如果数组长度为奇数, 那么就建立右孩子
    if (a.size() % 2 == 1) {
        nodeList[lastParent].right = &nodeList[lastParent * 2 + 2];
    }
    return nodeList;
}

int main(int argc, char *argv[])
{
    {
        vector<int> a{1, 2, 3, 4, 5, 6, 7};
        vector<TreeNode> nodeList = createBinTree(a);
        // 第一个结点就是根结点
        TreeNode *root = &nodeList[0];
        inorder(root);
    }
    return 0;
}
