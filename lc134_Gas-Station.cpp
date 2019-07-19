#include "lc/lc.h"
using namespace std;

// Runtime: 184 ms, faster than 10.47% of C++ online submissions for Gas Station.
// Memory Usage: 9 MB, less than 77.98% of C++ online submissions for Gas Station.
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();
        int ret = -1;
        for (int i = 0; i < n; ++i) {
            int j = i;
            int all = 0;
            // TODO: 隐蔽循环变量的LOOP宏
            int repeat = n;
            while (repeat) {
                all += gas[j];
                if (all >= cost[j]) {
                    all -= cost[j];
                    // NOTE repeat--在这里操作才合理
                    repeat--;
                }
                else
                    break;
                j = (j + 1) % n;
            }

            if (repeat == 0) {
                ret = i;
                break;
            }
        }
        return ret;
    }
};

int main()
{
    Solution sol;

    vector<int> gas1 = {1, 2, 3, 4, 5};
    vector<int> cost1 = {3, 4, 5, 1, 2};
    assert(sol.canCompleteCircuit(gas1, cost1) == 3);

    vector<int> gas2 = {2, 3, 4};
    vector<int> cost2 = {3, 4, 3};
    assert(sol.canCompleteCircuit(gas2, cost2) == -1);

    vector<int> gas3 = {4, 5, 3, 1, 4};
    vector<int> cost3 = {5, 4, 3, 4, 2};
    assert(sol.canCompleteCircuit(gas3, cost3) == -1);

    return 0;
}
