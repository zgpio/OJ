#include "lc/lc.h"
using namespace std;

// Runtime: 12 ms, faster than 89.00% of C++ online submissions for Remove Duplicates from Sorted Array II.
// Memory Usage: 8.7 MB, less than 63.42% of C++ online submissions for Remove Duplicates from Sorted Array II.
class Solution {
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() < 3) return nums.size();

        // for (auto i = nums.begin(); i <= nums.end() - 3;) {
        //     if (*i == *(i + 1)) {
        //         nums.erase(i);
        //     }
        //     else
        //         ++i;
        // }
        for (auto i = nums.begin(); i < nums.end() - 2;) {
            if (*(i + 2) == *i) {
                auto j = i + 3;
                while (j < nums.end() && *j == *i)
                    j++;
                nums.erase(i + 2, j);
            }
            ++i;
        }

        // for (auto i : nums)
        //     std::cout << i << " ";
        // std::cout << std::endl;
        return nums.size();
    }
};

int main()
{
    Solution sol;

    vector<int> t1 = {1, 1, 1, 2, 2, 3};
    vector<int> a1 = {1, 1, 2, 2, 3};
    assert(sol.removeDuplicates(t1) == 5);
    assert(t1 == a1);

    vector<int> t2 = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    vector<int> a2 = {0, 0, 1, 1, 2, 3, 3};
    assert(sol.removeDuplicates(t2) == 7);
    assert(t2 == a2);

    vector<int> t4 = {1, 1, 1};
    vector<int> a4 = {1, 1};
    assert(sol.removeDuplicates(t4) == 2);
    assert(t4 == a4);

    vector<int> t3 = {};
    vector<int> a3 = {};
    assert(sol.removeDuplicates(t3) == 0);
    assert(t3 == a3);
    return 0;
}
