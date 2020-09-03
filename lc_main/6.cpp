#include <bits/stdc++.h>
using namespace std;

// 6. ZigZag Conversion
class Solution {
public:
    string convert(string s, int numRows)
    {
        string ret;
        map<int, list<char>> dat;
        int dir = 0, i = 0, cnt = 0;
        while (s[i]) {
            if (cnt == 0 || cnt == numRows - 1) dir = !dir;
            auto ser = dat.find(cnt);
            if (ser != dat.end()) {
                dat[cnt].push_back(s[i]);
            }
            else {
                dat[cnt] = list<char>{s[i]};
            }
            if (numRows != 1) {
                if (dir)
                    ++cnt;
                else
                    --cnt;
            }
            ++i;
        }
        for (int i = 0; i < numRows; ++i) {
            if (dat.find(i) != dat.end()) {
                for (auto it = dat[i].begin(); it != dat[i].end(); ++it) {
                    ret.append(string{*it});
                }
            }
        }
        return ret;
    }
};

int main()
{
    Solution sol;
    assert(sol.convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR");
    assert(sol.convert("PAYPALISHIRING", 4) == "PINALSIGYAHRPI");
    assert(sol.convert("AB", 1) == "AB");
    std::cout << "end" << std::endl;
    return 0;
}
