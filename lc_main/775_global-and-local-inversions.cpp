#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIdealPermutation(vector<int> &A)
    {
        const int n = A.size();
        if (n == 0) return true;
        // NOTE: 只要存在max{A[0], ..., A[i]} > A[i+2], 0<=i<n-2,
        // 全局倒置数和局部倒置数就不同. m 维护了max{A[0], ..., A[i]}.
        int m = A[0];
        for (int i = 0; i < n - 2; ++i) {
            if (m > A[i + 2]) return false;
            if (A[i + 1] > m) m = A[i + 1];
        }
        return true;
    }
};

int main()
{
    Solution sol;

    vector<int> t1 = {1, 0, 2};
    vector<int> t2 = {1, 2, 0};
    vector<int> t3 = {0, 1, 2};
    assert(sol.isIdealPermutation(t1) == true);
    assert(sol.isIdealPermutation(t2) == false);
    assert(sol.isIdealPermutation(t3) == true);

    return 0;
}
