#include <assert.h>
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

// 11. Container With Most Water
// TODO: 优化
class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int xi = 0, yi = height[0], xj = 1, yj = height[1],
            val = min(yi, yj) * (xj - xi);
        for (int i = 0; i < height.size(); ++i) {
            for (int j = i + 1; j < height.size(); ++j) {
                // if (j - i <= xj - xi && min(height[i], height[j]) <= min(yi,
                // yj))
                //     continue;
                long long area = min(height[i], height[j]) * (j - i);
                if (area > val) {
                    xi = i, yi = height[i];
                    xj = j, yj = height[j];
                    val = area;
                }
                // std::cout << height[i] << height[j] << " ";
            }
            // std::cout << std::endl;
        }
        return val;
    }
};

class Solution2 {
public:
    int maxArea(vector<int>& height)
    {
        int maxarea = 0, l = 0, r = height.size() - 1;
        while (l < r) {
            maxarea = max(maxarea, min(height[l], height[r]) * (r - l));
            if (height[l] < height[r])
                l++;
            else
                r--;
        }
        return maxarea;
    }
};

int main()
{
    Solution sol;
    Solution2 sol2;
    vector<int> a = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    assert(sol.maxArea(a) == 49);
    assert(sol2.maxArea(a) == 49);
    std::cout << "end" << std::endl;
    return 0;
}
