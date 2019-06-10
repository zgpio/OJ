#include <assert.h>
#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <string>
#include <tuple>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n)
    {
        int i = 0, j = 0;
        int cnt = 1;
        vector<vector<int>> ans(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            int sx = i, sy = i;
            int ex = n - i - 1, ey = n - i - 1;
            for (int j = sx; j <= ex; ++j) ans[sx][j] = cnt++;
            for (int j = sx + 1; j <= ex; ++j) ans[j][ey] = cnt++;
            for (int j = ex - 1; j >= sx; --j) ans[ex][j] = cnt++;
            for (int j = ey - 1; j > sy; --j) ans[j][sx] = cnt++;
        }
        for (auto i : ans) {
            for (auto j : i) std::cout << j << " ";
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
