# from itertools import combinations
from typing import List


class Solution:
    def totalHammingDistance(self, nums: List[int]) -> int:
        # Elements of the given array are in the range of 0 to 10^9
        cnt = [0] * 32
        for e in nums:
            for i, bit in enumerate(bin(e)[-1:1:-1]):
                if bit == "1":
                    cnt[i] += 1

        print(cnt)

        # Length of the array will not exceed 10^4.
        res = 0
        for i in cnt:
            res += i * (len(nums) - i)

        return res


def main():

    sol = Solution()
    t = [4, 14, 2]
    assert sol.totalHammingDistance(t) == 6


if __name__ == "__main__":
    main()
