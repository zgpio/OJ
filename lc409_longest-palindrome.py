from itertools import combinations
from typing import List


class Solution:
    def longestPalindrome(self, s: str) -> int:
        d = {}
        for i in s:
            if i in d:
                d[i] += 1
            else:
                d[i] = 1
        res = 0
        flag = False
        for k, v in d.items():
            if v > 1:
                if v % 2 == 0:
                    res += v
                else:
                    res += v - 1
                    flag = True
            else:
                flag = True

        if flag:
            res += 1

        return res


def main():

    sol = Solution()
    inp = "bccccdda"
    assert sol.longestPalindrome(inp) == 7


if __name__ == "__main__":
    main()
