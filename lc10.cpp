#include "lc/lc.h"
using namespace std;

// TODO
class Solution {
public:
    bool isMatch(string s, string p)
    {
        char* c = new char[p.length()];
        int* mod = new int[p.length()];
        memset(mod, 0, sizeof(int) * p.length());

        string::iterator si = s.begin(), pi = p.begin();
        int cnt = 0;
        while (pi != p.end()) {
            // 断言第一个字符不是*
            c[cnt] = *pi;
            if (pi + 1 != p.end() && *(pi + 1) == '*') {
                mod[cnt] = 1;
                pi += 2;
            }
            else
                pi++;
            cnt++;
        }
        for (int i = 0; i < cnt; ++i) {
            std::cout << c[i] << ": " << mod[i] << "  ";
        }
        std::cout << std::endl<<std::endl;
        int i = 0;
        while (si != s.end()) {
            if (mod[i] == 0) {
                if (c[i] == *si || c[i] == '.') {
                    i++;
                    si++;
                }
                else
                    return false;
            }
            else {  // *模式, 策略: 匹配尽可能多的重复
                if (c[i] == *si || c[i] == '.') {
                    char t = *si;
                    while (si != s.end() && (t == *(++si) || c[i] == '.') &&
                           s.end() - si >= cnt - i)
                        ;
                    i++;
                }
                else
                    i++;
            }
            if (si == s.end()) {
                while (mod[i] != 0) i++;
            }
        }
        if (si == s.end() && i == cnt)
            return true;
        else
            return false;
    }
};

int main()
{
    Solution sol;
    assert(sol.isMatch("abb", "a.b") == true);
    assert(sol.isMatch("abb", "a*.b") == true);
    assert(sol.isMatch("aaab", "a*ab") == true);
    assert(sol.isMatch("ab", ".*") == true);
    assert(sol.isMatch("aba", ".*a") == true);
    assert(sol.isMatch("aab", "c*a*b*") == true);
    assert(sol.isMatch("aaa", "aaaa") == false);
    assert(sol.isMatch("a", "ab*") == true);
    assert(sol.isMatch("bbbba", ".*a*a") == true);

    std::cout << "end" << std::endl;
    return 0;
}
