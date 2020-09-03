#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path)
    {
        std::cout << ">>>input: " << path << std::endl;
        const char *s = path.c_str();
        const int n = path.size();
        deque<string> st;
        // s[i] != '\0' 造成 AddressSanitizer: heap-buffer-overflow
        // NOTE: 不建议使用s[i]作为关系表达式
        for (int i = 0; i < n; ++i) {
            char t[50];

            while (i < n && s[i] == '/') {
                i++;
            }
            int j = 0;
            while (i < n && s[i] != '/') {
                t[j++] = s[i++];
            }
            t[j] = '\0';
            if (strcmp(t, "..") == 0) {
                std::cout << "find.. -> ";
                if (!st.empty()) st.pop_back();
            }
            else if (strcmp(t, ".") == 0) {
                std::cout << "find. -> ";
            }
            else if (strcmp(t, "")) {
                st.push_back(t);
            }
        }
        string res;
        std::cout << "size: " << st.size() << " ";
        while (!st.empty()) {
            res.push_back('/');
            res += st.front();
            st.pop_front();
        }

        if (res == "") res = "/";
        std::cout << "result: " << res << std::endl;
        return res;
    }
};

int main()
{
    Solution sol;

    assert(sol.simplifyPath("/home/") == "/home");
    assert(sol.simplifyPath("/a//b////c/d//././/..") == "/a/b/c");
    assert(sol.simplifyPath("/home//foo/") == "/home/foo");
    assert(sol.simplifyPath("/a/./b/../../c/") == "/c");
    assert(sol.simplifyPath("/../") == "/");
    assert(sol.simplifyPath("/a/../../b/../c//.//") == "/c");

    return 0;
}
