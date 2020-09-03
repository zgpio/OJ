#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //         x: 0, 1, ..., L/2
    //  偏置bias: 0, 1, ..., l-2
    //
    //    ┌────────────────────┐
    //    │(x,x)│    │ ①  │    │
    //    │─────│────│────│────│
    //    │     │    │    │ ④  │
    //  l │─────│────│────│────│
    //    │  ②  │    │    │    │
    //    │─────│────│────│────│
    //    │     │    │ ③  │    │
    //    └────────────────────┘
    //              l
    //
    // 四个角坐标:
    //   (x,x), (x,x+l-1), (x+l-1,x+l-1), (x+l-1,x)
    //
    // ① (x, x+b)
    // ② (x+l-1-b, x)
    // ③ (x+l-1, x+l-1-b)
    // ④ (x+b, x+l-1)
    //
    void rotate(vector<vector<int>> &matrix)
    {
        int L = matrix.size();
        int X = L / 2;
        for (int x = 0; x <= X; ++x) {
            int l = L - x * 2;
            for (int b = 0; b <= l - 2; ++b) {
                int t = matrix[x][x + b];
                matrix[x][x + b] = matrix[x + l - 1 - b][x];
                matrix[x + l - 1 - b][x] = matrix[x + l - 1][x + l - 1 - b];
                matrix[x + l - 1][x + l - 1 - b] = matrix[x + b][x + l - 1];
                matrix[x + b][x + l - 1] = t;
            }
        }
    }
};
void printM(vector<vector<int>> m)
{
    for (auto i : m) {
        for (auto j : i) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    Solution sol;
    typedef vector<vector<int>> matrix;
    // clang-format off
    matrix t1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    matrix a1 = {
        {7, 4, 1},
        {8, 5, 2},
        {9, 6, 3}};
    matrix t2 = {
        {5, 1, 9, 11},
        {2, 4, 8, 10},
        {13, 3, 6, 7},
        {15, 14, 12, 16}};
    matrix a2 = {
        {15, 13, 2, 5},
        {14, 3, 4, 1},
        {12, 6, 8, 9},
        {16, 7, 10, 11}};
    // clang-format on
    sol.rotate(t1);
    sol.rotate(t2);
    printM(t1);
    assert(t1 == a1);
    assert(t2 == a2);

    return 0;
}
