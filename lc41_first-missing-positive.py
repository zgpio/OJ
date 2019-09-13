# from itertools import combinations
from typing import List


class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        # NOTE: return ∈ {1, ..., n+1}, where len(nums)=n.
        n = len(nums)
        # NOTE: 负整数和0覆盖为无效整数
        for i in range(n):
            if nums[i] <= 0:
                nums[i] = n + 2

        for i in nums:
            idx = abs(i) - 1
            if idx < n:
                nums[idx] = -abs(nums[idx])

        # print(nums)
        # NOTE: nums[i]的正表示(i+1)不存在
        for i in range(n):
            if nums[i] > 0:
                return i + 1
        return n + 1


def main():

    sol = Solution()

    inp = [1, 2, 0]
    out = 3
    assert sol.firstMissingPositive(inp) == out
    inp = [3, 4, -1, 1]
    out = 2
    assert sol.firstMissingPositive(inp) == out
    inp = [7, 8, 9, 11, 12]
    out = 1
    assert sol.firstMissingPositive(inp) == out


if __name__ == "__main__":
    main()
