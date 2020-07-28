#include "lc/lc.h"
using namespace std;

// 剑指 Offer 29. 顺时针打印矩阵
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    if (m == 0) return {};
    int n = matrix[0].size();
    vector<int> ans;

    // m行n列, x索引行, y索引列
    for (int i = 0; i < n && i < m; ++i) {
        int sx = i, ex = m - i - 1;
        int sy = i, ey = n - i - 1;
        if (!(ex >= sx && ey >= sy)) break;
        if (ex == sx)
            for (int j = sy; j <= ey; ++j) ans.push_back(matrix[sx][j]);
        else if (sy == ey)
            for (int j = sx; j <= ex; ++j) ans.push_back(matrix[j][sy]);
        else {
            // ────│
            // │   │
            // │────
            for (int j = sy; j < ey; ++j) ans.push_back(matrix[sx][j]);
            for (int j = sx; j < ex; ++j) ans.push_back(matrix[j][ey]);
            for (int j = ey; j > sy; --j) ans.push_back(matrix[ex][j]);
            for (int j = ex; j > sx; --j) ans.push_back(matrix[j][sy]);
        }
    }

    return ans;
}

vector<vector<int>> genSpiralOrder(int n, int m) // n行m列, y索引行, x索引列
{
    assert(m > 0 && n > 0);
    vector<vector<int>> rv(n, vector<int>(m, 0));

    int t = 0;
    for (int i = 0; i < n && i < m; ++i) {
        int sx = i, ex = m - i - 1;
        int sy = i, ey = n - i - 1;
        if (!(ex >= sx && ey >= sy)) break;
        if (sx == ex)
            for (int j = sy; j <= ey; ++j) rv[j][sx] = t++;
        else if (sy == ey)
            for (int j = sx; j <= ex; ++j) rv[sy][j] = t++;
        else {
            // ────│
            // │   │
            // │────
            for (int j = sx; j < ex; ++j) rv[sy][j] = t++;
            for (int j = sy; j < ey; ++j) rv[j][ex] = t++;
            for (int j = ex; j > sx; --j) rv[ey][j] = t++;
            for (int j = ey; j > sy; --j) rv[j][sx] = t++;
        }
    }

    return rv;
}

int main()
{
    vector<pair<vector<vector<int>>, vector<int>>> cases = {
        {
            {{1, 2, 3},
             {8, 9, 4},
             {7, 6, 5}}, {1, 2, 3, 4, 5, 6, 7, 8, 9}
        },
        {
            {{ 1,  2,  3, 4},
             {12, 13, 14, 5},
             {11, 16, 15, 6},
             {10,  9,  8, 7}}, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16}
        },
        {
            {{3},
             {2}}, {3, 2}
        },
        {
            {{1, 2, 3, 4},
             {5, 6, 7, 8},
             {9, 10, 11, 12}}, {1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7}
        },
        {
            {{6, 9, 7}}, {6, 9, 7}
        },
        {
            {{7},
             {9},
             {6}}, {7, 9, 6}
        }

    };
    for (auto c:cases) {
        assert(spiralOrder(c.first)==c.second);
    }
    genSpiralOrder(5, 4);
    genSpiralOrder(4, 5);
    return 0;
}
