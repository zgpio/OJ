from itertools import combinations
from typing import List


class Solution:
    def findLHS(self, nums: List[int]) -> int:
        n = len(nums)
        if n <= 1:
            return 0
        nums = sorted(nums)
        p1 = p2 = 0
        cnt = 0
        while p2 != n - 1:
            while p2 != n - 1 and nums[p2] - nums[p1] <= 1:
                p2 += 1

            if (nums[p2 - 1] - nums[p1] == 1):
                cnt = max(p2 - p1, cnt)
            if (nums[p2] - nums[p1] == 1):
                cnt = max(p2 - p1 + 1, cnt)

            while nums[p2] - nums[p1] >= 2:
                p1 += 1

        return cnt


def main():

    sol = Solution()
    inp = [1, 3, 2, 2, 5, 2, 3, 7]
    ans = 5
    assert sol.findLHS(inp) == ans

    inp = [1, 1, 1, 1]
    ans = 0
    assert sol.findLHS(inp) == ans

    inp = []
    ans = 0
    assert sol.findLHS(inp) == ans

    inp = [1, 2, 2, 1]
    ans = 4
    assert sol.findLHS(inp) == ans

    inp = [1]
    ans = 0
    assert sol.findLHS(inp) == ans


if __name__ == "__main__":
    main()
