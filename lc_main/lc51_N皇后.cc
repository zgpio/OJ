#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    int N;
    int *Queenes;
    int Counts = 0;
    vector<vector<string>> res;

public:
    vector<vector<string>> solveNQueens(int n)
    {
        N = n;
        res.clear();
        Queenes = new int[N];

        n_queen(0);
        delete[] Queenes;
        return res;
    }
    int Check(int row, int col)
    {
        for (int i = 0; i < row; i++) {
            int j = Queenes[i];
            if (col == j) {
                return 0;
            }
            if ((i + j) == (row + col)) { // ⧄
                return 0;
            }
            if ((i - j) == (row - col)) { // ⧅
                return 0;
            }
        }
        return 1;
    }

    void dump()
    {
        vector<string> vs;
        for (int row = 0; row < N; row++) {
            int col;
            string s;
            for (col = 0; col < Queenes[row]; col++)
                s.append(".");
            s.append("Q");
            for (col = Queenes[row] + 1; col < N; col++) {
                s.append(".");
            }
            vs.push_back(s);
        }
        res.push_back(vs);
    }
    // 特别注意: 递归调用之后不需要重置Queenes
    void n_queen(int row)
    {
        for (int col = 0; col < N; col++) {
            if (Check(row, col)) {
                Queenes[row] = col;
                if (row == N - 1) {
                    Counts++;
                    dump();
                    return;
                }
                n_queen(row + 1);
            }
        }
    }
};

int main()
{
    Solution s;
    auto res = s.solveNQueens(4);
    for (auto i : res) {
        for (auto j : i) {
            cout << j << endl;
        }
        cout << endl;
    }
    return 0;
}
