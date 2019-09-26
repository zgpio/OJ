# from itertools import combinations
from typing import List
from math import sqrt


# 1 ≤ nums[i] ≤ n (where n = len(nums)), some elements appear twice and others appear once.
# Find all the elements of [1, n] inclusive that do not appear in this array.
# Requirements: without extra space and in O(n) runtime.

class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        for i in nums:
            idx = abs(i) - 1
            if nums[idx] > 0:
                nums[idx] = -nums[idx]
        res = []
        for i in range(len(nums)):
            if nums[i] > 0:
                res.append(i + 1)
        return res


def main():

    sol = Solution()
    nums = [4, 3, 2, 7, 8, 2, 3, 1]
    ans = [5, 6]
    assert sol.findDisappearedNumbers(nums) == ans


if __name__ == "__main__":
    main()
