#include <iostream>
#include <vector>
using namespace std;

// 左下或右上角
// ┌─▶─┐
// ▼   ▼
// └─▶─┘
class Solution
{
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        const int n = matrix.size();
        if (n == 0)
            return false;
        const int m = matrix[0].size();
        if (m == 0)
            return false;
        int i = n - 1, j = 0;
        while (i >= 0 && j < m) {
            if (matrix[i][j] > target) {
                i--;
            } else if (matrix[i][j] < target) {
                j++;
            } else
                return true;
        }
        return false;
    }
};

int main(int argc, char* argv[])
{
    vector<vector<int>> m
        = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    Solution s;
    assert(s.searchMatrix(m, 5) == true);
    assert(s.searchMatrix(m, 20) == false);
    {
        vector<vector<int>> m = {{-5}};
        assert(s.searchMatrix(m, -5) == true);
    }
    {
        vector<vector<int>> m = {{}};
        assert(s.searchMatrix(m, -5) == false);
    }
    {
        vector<vector<int>> m = {{-1, 3}};
        assert(s.searchMatrix(m, 3) == true);
    }

    return 0;
}
