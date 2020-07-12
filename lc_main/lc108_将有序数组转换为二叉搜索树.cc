#include "lc/bt.h"
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return helper(nums, 0, nums.size() - 1);
    }
    TreeNode *helper(vector<int> &nums, int L, int R)
    {
        if (L > R) return nullptr;
        int M = (L + R) / 2;
        TreeNode *root = new TreeNode(nums[M]);
        TreeNode *lt = helper(nums, L, M - 1);
        TreeNode *rt = helper(nums, M + 1, R);
        root->left = lt;
        root->right = rt;
        return root;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<int> a{1, 2, 3, 4, 5};
    auto t = s.sortedArrayToBST(a);
    preorder(t);
    return 0;
}
