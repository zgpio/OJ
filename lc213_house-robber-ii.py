# from itertools import combinations
from typing import List


class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 0:
            return 0
        elif n == 1:
            return nums[0]

        return max(self.__dp(nums[1:]), nums[0] + self.__dp(nums[2:-1]))

    def __dp(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 0:
            return 0
        elif n == 1:
            return nums[0]

        # dp[i]表示{nums[0], ..., nums[i]}的robber-I问题的最优解
        dp = [nums[0], max(nums[0], nums[1])]
        for i in range(2, n):
            dp.append(max(dp[i - 1], nums[i] + dp[i - 2]))
        return dp[-1]


def main():

    sol = Solution()
    t = [2, 3, 2]
    assert sol.rob(t) == 3

    t = [1, 2, 3, 1]
    assert sol.rob(t) == 4

    t = []
    assert sol.rob(t) == 0


if __name__ == "__main__":
    main()
