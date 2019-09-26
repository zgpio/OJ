from itertools import combinations
from typing import List

# 找出所有相加之和为 n 的 k 个数的组合.
# 组合中只允许含有 1 - 9 的正整数, 并且每种组合中不存在重复的数字.


class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        nums = range(1, 10)
        ans = []
        # TODO: 递归生成组合数时验证条件来进行剪枝
        for lst in combinations(nums, k):
            if sum(lst) == n:
                ans.append(list(lst))

        return ans


def main():

    sol = Solution()
    k = 3
    n = 7
    assert sol.combinationSum3(k, n) == [[1, 2, 4]]

    k = 3
    n = 9
    assert sol.combinationSum3(k, n) == [[1, 2, 6], [1, 3, 5], [2, 3, 4]]


if __name__ == "__main__":
    main()
