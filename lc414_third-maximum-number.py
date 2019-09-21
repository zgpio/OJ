from itertools import combinations
from typing import List


class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        m1 = max(nums)
        nums = list(filter(lambda x: x != m1, nums))
        if len(nums) == 0:
            return m1
        m2 = max(nums)
        nums = list(filter(lambda x: x != m2, nums))
        if len(nums) == 0:
            return m1
        m3 = max(nums)
        return m3


def main():

    sol = Solution()

    nums = [3, 2, 1]
    ans = 1
    assert sol.thirdMax(nums) == ans
    nums = [1, 2]
    ans = 2
    assert sol.thirdMax(nums) == ans
    nums = [2, 2, 3, 1]
    ans = 1
    assert sol.thirdMax(nums) == ans


if __name__ == "__main__":
    main()
