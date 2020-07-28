#include "lc/lc.h"
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        if (matrix.size() == 0) return false;
        if (matrix[0].size() == 0) return false;
        for (auto row : matrix) {
            if (std::binary_search(row.begin(), row.end(), target))
                return true;
            else if (row[0] < target && target < row.back())
                return false;
        }
        return false;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
    vector<vector<int>> m2 = {{}};
    vector<vector<int>> m3 = {};
    int target = 3;
    int target2 = 4;

    assert(sol.searchMatrix(matrix, target));
    assert(!sol.searchMatrix(matrix, target2));
    assert(!sol.searchMatrix(m2, target));
    assert(!sol.searchMatrix(m3, target));
    return 0;
}
