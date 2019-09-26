# from itertools import combinations
from typing import List


class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        '''
        1 <= k <= n <= 30000
        所给数据范围 [-10000，10000]
        '''
        n = len(nums)
        s = sum(nums[:k])
        maxs = s
        for i in range(1, n - k + 1):
            s -= nums[i - 1]
            s += nums[i + k - 1]
            maxs = max(maxs, s)

        return maxs / k


def main():

    sol = Solution()
    inp = [1, 12, -5, -6, 50, 3]
    k = 4
    ans = 12.75
    assert sol.findMaxAverage(inp, k) == ans
    inp = [0, 1, 1, 3, 3]
    k = 4
    ans = 2.0
    assert sol.findMaxAverage(inp, k) == ans


if __name__ == "__main__":
    main()
