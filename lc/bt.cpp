#include "bt.h"
#include <queue>
#include <unordered_map>
#include <iostream>

using std::vector;
using std::string;

static vector<string> split(const string& str, const string& delim) {
    vector<string> res;
    if("" == str) return res;
    char * strs = new char[str.length() + 1] ;
    strcpy(strs, str.c_str());

    const char * d = delim.c_str();

    char *p = strtok(strs, d);
    while (p) {
        string s = p; // 分割得到的字符串转换为string类型
        res.push_back(s);
        p = strtok(NULL, d);
    }

    delete[] strs;
    return res;
}
std::string& trim(std::string &s)
{
    if (s.empty())
    {
        return s;
    }

    s.erase(0,s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);
    return s;
}

// "[]"
// 列表中的元素必须是int类型或null, 用逗号分隔
// 支持方括号/花括号
TreeNode *constructT(std::string a)
{
    std::unordered_map<int, int> m;
    int spos = a.find_last_of("[");
    if (spos==string::npos) spos = a.find_last_of("{");
    if (spos==string::npos) spos = a.find_last_of("(");
    int epos = a.find_first_of("]");
    if (epos==string::npos) epos = a.find_first_of("}");;
    if (epos==string::npos) epos = a.find_first_of(")");;
    a = a.substr(spos+1, epos-(spos+1));
    auto strs = split(a, ",");
    int i = -1;
    for (auto &s:strs)
    {
        i++;
        s = trim(s);
        if (s=="null")
            continue;
        int n = atoi(s.c_str());
        m[i] = n;
    }

    const int L = i+1;
    if (L == 0) return nullptr;
    std::queue<TreeNode *> q;
    TreeNode *T = new TreeNode(m[0]);
    q.push(T);
    for (int i = 0; i * 2 + 1 < L; ++i) {
        TreeNode *t = q.front();
        q.pop();

        auto got = m.find(i * 2 + 1);
        if (got != m.end()) {
            t->left = new TreeNode(got->second);
            q.push(t->left);
        }
        got = m.find(i * 2 + 2);
        if (got != m.end()) {
            t->right = new TreeNode(got->second);
            q.push(t->right);
        }
    }
    return T;
}

void preorder(TreeNode *t)
{
    if (t) {
        std::cout << t->val << " ";
        preorder(t->left);
        preorder(t->right);
    }
}
static void inorder_(TreeNode *t)
{
    if (t != NULL) {
        inorder_(t->left);
        std::cout << t->val << " ";
        inorder_(t->right);
    }
}
void inorder(TreeNode *t)
{
    inorder_(t);
    std::cout << std::endl;
}
