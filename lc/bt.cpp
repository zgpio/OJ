#include "bt.h"
#include <cstring>
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
// 支持方括号/花括号/圆括号
static vector<TreeNode *> parse_level_order(string a)
{
    vector<TreeNode *> rv;
    int spos = a.find_last_of("[");
    if (spos==string::npos) spos = a.find_last_of("{");
    if (spos==string::npos) spos = a.find_last_of("(");
    int epos = a.find_first_of("]");
    if (epos==string::npos) epos = a.find_first_of("}");;
    if (epos==string::npos) epos = a.find_first_of(")");;
    a = a.substr(spos+1, epos-(spos+1));
    auto strs = split(a, ",");
    for (auto &s:strs)
    {
        s = trim(s);
        if (s=="null")
            rv.push_back(nullptr);
        else {
            int key = atoi(s.c_str());
            rv.push_back(new TreeNode(key));
        }
    }
    return rv;
}

TreeNode *constructT(std::string a)
{
    vector<TreeNode *> v = parse_level_order(a);  // index(0-based) -> key
    if (v.size() == 0) return nullptr;

    std::queue<TreeNode *> q;
    TreeNode *T = new TreeNode(v[0]->val);
    q.push(T);
    int i = 1;
    while (!q.empty() && i < v.size()) {
        TreeNode *t = q.front();
        q.pop();

        auto lc = v[i];
        if (lc != nullptr) {
            t->left = lc;
            q.push(t->left);
        }
        i++;
        if (i < v.size()) {
            auto rc = v[i];
            if (rc != nullptr) {
                t->right = rc;
                q.push(t->right);
            }
            i++;
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
