#include "lc/lc.h"
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        int m = matrix.size();
        if (m == 0) return {};
        int n = matrix[0].size();
        vector<int> ans;
        std::cout << m << " " << n << std::endl;

        // TODO: 应该还可以更加清晰
        for (int i = 0; i < n && i < m; ++i) {
            int sx = i, sy = i;
            int ex = m - i - 1, ey = n - i - 1;
            if (!(ex >= sx && ey >= sy)) break;
            if (ex == sx)
                for (int j = sy; j <= ey; ++j) ans.push_back(matrix[sx][j]);
            else if (sy == ey)
                for (int j = sx; j <= ex; ++j) ans.push_back(matrix[j][ey]);
            else {
                for (int j = sy; j <= ey; ++j) ans.push_back(matrix[sx][j]);
                for (int j = sx + 1; j <= ex; ++j) ans.push_back(matrix[j][ey]);
                for (int j = ey - 1; j >= sy; --j) ans.push_back(matrix[ex][j]);
                for (int j = ex - 1; j > sx; --j) ans.push_back(matrix[j][sy]);
            }
        }

        for (auto i : ans) std::cout << i << " ";
        std::cout << std::endl;

        return ans;
    }
};
int main()
{
    Solution sol;
    vector<vector<int>> t1 = {{1, 2, 3}, {8, 9, 4}, {7, 6, 5}};
    vector<vector<int>> t2 = {
        {1, 2, 3, 4}, {12, 13, 14, 5}, {11, 16, 15, 6}, {10, 9, 8, 7}};
    vector<vector<int>> t3 = {{3}, {2}};
    vector<vector<int>> t4 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    vector<vector<int>> t5 = {{6, 9, 7}};
    vector<vector<int>> t6 = {{7}, {9}, {6}};
    vector<int> a1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // assert(sol.spiralOrder(t1) == a1);
    // sol.spiralOrder(t2);
    sol.spiralOrder(t3);
    sol.spiralOrder(t6);
    // sol.spiralOrder(t4);
    sol.spiralOrder(t5);
    return 0;
}
