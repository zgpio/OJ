#include <bits/stdc++.h>
using namespace std;

// 最长连续整数序列
int longestConsecutive(vector<int> &nums)
{
    unordered_set<int> num_set;
    for (const int &num : nums) {
        num_set.insert(num);
    }

    int longestStreak = 0;

    // 时间复杂度为 O(n)
    for (const int &num : num_set) {
        if (!num_set.count(num - 1)) {
            int j = num + 1;
            int currentStreak = 1;

            while (num_set.count(j)) {
                j += 1;
                currentStreak += 1;
            }

            longestStreak = max(longestStreak, currentStreak);
        }
    }

    return longestStreak;
}

int main(int argc, char *argv[])
{
    {
        vector<int> a{100, 4, 200, 1, 3, 2};
        assert(longestConsecutive(a) == 4);
    }
    {
        vector<int> a{0};
        assert(longestConsecutive(a) == 1);
    }
    return 0;
}
