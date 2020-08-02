#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct TreeNode {
    struct TreeNode *left = nullptr;
    struct TreeNode *right = nullptr;
    TreeNode() : left(nullptr), right(nullptr)
    {
    }
    TreeNode(char elem) : left(nullptr), right(nullptr), elem(elem)
    {
    }
    char elem;
};

class Solution
{
   public:
    string InPre2Post(const char *inorder, const char *preorder, const int length)
    {
        s.clear();
        BinaryTreeFromOrderings(inorder, preorder, length);
        return s;
    }
    string InPost2Pre(const char *inorder, const char *postorder, const int length)
    {
        s.clear();
        string in = inorder;
        string post = postorder;
        TreeNode *t = buildTreeCore(in, 0, length - 1, post, 0, length - 1);
        preorder(t);
        return s;
    }

   private:
    string s;
    void preorder(TreeNode *t)
    {
        if (t) {
            s.push_back(t->elem);
            preorder(t->left);
            preorder(t->right);
        }
    }
    TreeNode *buildTreeCore(string &in, int inStart, int inEnd, string &post, int postStart, int postEnd)
    {
        if (inStart > inEnd || postStart > postEnd)
            return nullptr;

        TreeNode *root = new TreeNode(post[postEnd]);
        for (int i = inStart; i <= inEnd; ++i) {
            if (in[i] == post[postEnd]) {
                root->left = buildTreeCore(in, inStart, i - 1, post, postStart, postStart + i - inStart - 1);
                root->right = buildTreeCore(in, i + 1, inEnd, post, postStart + i - inStart, postEnd - 1);
            }
        }
        return root;
    }
    TreeNode *BinaryTreeFromOrderings(const char *inorder, const char *preorder, const int length)
    {
        if (length == 0) {
            return nullptr;
        }
        TreeNode *node = new TreeNode;
        node->elem = *preorder;
        int rootIndex = 0;
        for (; rootIndex < length; rootIndex++)  // a variation of the loop
        {
            if (inorder[rootIndex] == *preorder)
                break;
        }
        node->left = BinaryTreeFromOrderings(inorder, preorder + 1, rootIndex);
        node->right
            = BinaryTreeFromOrderings(inorder + rootIndex + 1, preorder + rootIndex + 1, length - (rootIndex + 1));
        s.push_back(node->elem);
        return node;
    }
};

int main(int argc, char **argv)
{
    Solution s;
    {
        char preorder[] = "GDAFEMHZ";
        char inorder[] = "ADEFGHMZ";
        string postorder = s.InPre2Post(inorder, preorder, 8);
        assert(postorder == "AEFDHZMG");
    }
    {
        char postorder[] = "AEFDHZMG";
        char inorder[] = "ADEFGHMZ";
        string preorder = s.InPost2Pre(inorder, postorder, 8);
        assert(preorder == "GDAFEMHZ");
    }
    {
        char preorder[] = "ABDFHCEG";
        char inorder[] = "HFDBACEG";
        string postorder = s.InPre2Post(inorder, preorder, 8);
        assert(postorder == "HFDBGECA");
    }
    {
        char postorder[] = "HFDBGECA";
        char inorder[] = "HFDBACEG";
        string preorder = s.InPost2Pre(inorder, postorder, 8);
        assert(preorder == "ABDFHCEG");
    }
    return 0;
}
