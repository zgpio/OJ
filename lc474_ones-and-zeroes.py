# from itertools import combinations
from typing import List


# Note:
# The given numbers of 0s and 1s will both not exceed 100
# The size of given string array won't exceed 600.
class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        # What the f*ck Python: https://github.com/leisurelicht/wtfpython-cn
        # dp = [[[0] * (n + 1)] * (m + 1)] * (l + 1)

        # arr3 = lambda m, n, l: [[[0 for k in range(l)] for j in range(n)]
        #                        for i in range(m)]
        # NOTE: 三维0-1背包问题: dp[i][j][k] 表示前i个01串,
        #       当有j个0, k个1时的最优解.
        #       转换为二维背包问时, 注意逆序递推
        arr2 = lambda m, n: [[0 for j in range(n)] for i in range(m)]
        dp = arr2(m + 1, n + 1)

        for s in strs:
            # NOTE: for j in i 或使用count函数
            x = s.count('0')
            y = s.count('1')
            for j in range(m, -1, -1):
                for k in range(n, -1, -1):
                    if j >= x and k >= y:
                        dp[j][k] = max(dp[j - x][k - y] + 1, dp[j][k])
                    else:
                        dp[j][k] = dp[j][k]

        return dp[m][n]


def main():

    sol = Solution()
    a = ["10", "0001", "111001", "1", "0"]
    m = 5
    n = 3
    assert sol.findMaxForm(a, m, n) == 4
    a = ["10", "0", "1"]
    m = 1
    n = 1
    assert sol.findMaxForm(a, m, n) == 2


if __name__ == "__main__":
    main()
