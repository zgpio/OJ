#include "lc/lc.h"
using namespace std;

class Solution
{
   public:
    vector<vector<int>> generateMatrix(int n)
    {
        int cnt = 1;
        vector<vector<int>> ans(n, vector<int>(n));
        // x索引行, y索引列
        for (int i = 0; i < n; ++i) {
            int sx = i, ex = n - i - 1;
            int sy = i, ey = n - i - 1;
            if (sx > ex) break;
            for (int j = sy; j < ey; ++j) ans[sx][j] = cnt++;
            for (int j = sx; j < ex; ++j) ans[j][ey] = cnt++;
            for (int j = ey; j > sy; --j) ans[ex][j] = cnt++;
            for (int j = ex; j > sx; --j) ans[j][sy] = cnt++;
        }
        if (n & 1) {  // n为奇数时中心需要赋值
            ans[n / 2][n / 2] = cnt++;
        }
        for (auto i : ans) {
            for (auto j : i)
                std::cout << j << " ";
            std::cout << std::endl;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> a1 = {{1, 2, 3}, {8, 9, 4}, {7, 6, 5}};
    assert(sol.generateMatrix(3) == a1);
    sol.generateMatrix(4);
    sol.generateMatrix(1);
    return 0;
}
