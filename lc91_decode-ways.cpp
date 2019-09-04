#include "lc/lc.h"
using namespace std;

class Solution {
    int cnt;

public:
    int numDecodings(string s)
    {
        cnt = 0;
        dfs(s.c_str());
        return cnt;
    }
    // NOTE 特别注意0
    void dfs(const char a[])
    {
        if (a[0] == '\0') {
            cnt++;
            return;
        }
        if (a[0] == '0')
            return;
        else {
            dfs(a + 1);
            if (a[1] != '\0') {
                if (a[0] == '1' || (a[0] == '2' && a[1] <= '6')) dfs(a + 2);
            }
        }
    }
};

int main()
{
    Solution sol;
    string t1 = "12";
    string t2 = "226";
    string t3 = "0";
    string t4 = "10";

    assert(sol.numDecodings(t1) == 2);
    assert(sol.numDecodings(t2) == 3);
    assert(sol.numDecodings(t3) == 0);
    assert(sol.numDecodings(t4) == 1);

    return 0;
}
