# from itertools import combinations
from typing import List


class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        # NOTE: 1 ≤ nums[i] ≤ n （n为数组长度）
        n = len(nums)
        for e in nums:
            nums[(e-1)%n]+=n

        res = []
        for i in range(n):
            if nums[i]-2*n>=1:
                res.append(i+1)
        print(res)
        return res

def main():

    sol = Solution()
    nums = [4,3,2,7,8,2,3,1]
    ans = [2, 3]
    assert sol.findDuplicates(nums)==ans
    nums = [10,2,5,10,9,1,1,4,3,7]
    ans = [1, 10]
    assert sol.findDuplicates(nums)==ans

if __name__ == "__main__":
    main()
