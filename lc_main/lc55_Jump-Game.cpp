#include "lc/lc.h"
using namespace std;

class Solution {
public:
    bool canJump(vector<int> &nums)
    {
        vector<int> a = nums;
        int s = 0;
        int n = a.size();
        for (int i = 0; i < n; ++i) {
            if (a[i] == 0) {
                int j;
                int max = 0;
                for (j = s; j < i; ++j) {
                    int d = a[j] - (i - j);
                    if (d > max) max = d;
                }
                if (max == 0&&i!=n-1)
                    return false;
                else {
                    s = i;
                    a[s] = max;
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    vector<int> t1 = {2, 3, 1, 1, 4};
    vector<int> t2 = {3, 2, 1, 0, 4};
    vector<int> t3 = {2, 0};
    vector<int> t4 = {2, 0, 0};
    vector<int> t5 = {0};
    assert(sol.canJump(t1) == true);
    assert(sol.canJump(t2) == false);
    assert(sol.canJump(t3) == true);
    assert(sol.canJump(t4) == true);
    assert(sol.canJump(t5) == true);
    return 0;
}
