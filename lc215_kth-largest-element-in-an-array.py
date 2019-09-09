# from itertools import combinations
from typing import List


class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        n = len(nums)
        assert 1 <= k <= n
        i = 0
        j = n - 1
        flag = nums[0]
        while i < j:
            while i < j and nums[j] <= flag:
                j -= 1
            nums[i] = nums[j]
            while i < j and nums[i] > flag:
                i += 1
            nums[j] = nums[i]

        nums[i] = flag
        if i == k - 1:
            return nums[i]
        elif i > k - 1:
            return self.findKthLargest(nums[:i], k)
        elif i < k - 1:
            return self.findKthLargest(nums[i + 1:], k - i - 1)


def main():

    sol = Solution()
    t = [3, 2, 1, 5, 6, 4]
    k = 2
    assert sol.findKthLargest(t, k) == 5

    t = [3, 2, 3, 1, 2, 4, 5, 5, 6]
    k = 4
    assert sol.findKthLargest(t, k) == 4


if __name__ == "__main__":
    main()
