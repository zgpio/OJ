#include <bits/stdc++.h>
#include <lc/bt.h>
using namespace std;

int klevel_cnt(TreeNode *t, int k)
{
    if (t) {
        if (k == 0) return 1;
        int l = klevel_cnt(t->left, k - 1);
        int r = klevel_cnt(t->right, k - 1);
        return l + r;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    //    1
    //  2   3
    // 4 5 6 7
    vector<tuple<string, int, int>> cases = {
        tuple<string, int, int>{"[1, 2, 3, 4, 5, 6, 7]", 2, 4},
        tuple<string, int, int>{"[]", 2, 0}};
    for (auto c : cases) {
        TreeNode *t = constructT(std::get<0>(c));
        inorder(t);
        assert(klevel_cnt(t, get<1>(c)) == get<2>(c));
    }
    return 0;
}
