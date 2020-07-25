#include <lc/bt.h>
#include <iostream>
using namespace std;

class Solution
{
    int cnt;
    int k;
    int rv;

   public:
    int kthLargest(TreeNode *root, int k)
    {
        this->k = k;
        cnt = 0;
        helper(root);
        return rv;
    }
    void helper(TreeNode *root)
    {
        if (root) {
            helper(root->right);
            if (cnt < k) {
                rv = root->val;
                cnt++;
            } else {
                return;
            }
            helper(root->left);
        }
    }
};

// 输入: root = [3,1,4,null,2], k = 1
//    3
//   / \
//  1   4
//   \
//    2
// 输出: 4
int main(int argc, char *argv[])
{
    Solution s;
    TreeNode *t = constructT("[3,1,4,null,2]");
    int pred = s.kthLargest(t, 1);
    assert(pred == 4);
    {
        TreeNode *t = constructT("[5,3,6,2,4,null,null,1]");
        int pred = s.kthLargest(t, 3);
        assert(pred == 4);
    }
    return 0;
}
