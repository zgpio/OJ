# from itertools import combinations
from typing import List
from math import sqrt


class Solution:
    def bulbSwitch(self, n: int) -> int:
        # NOTE: 因数成对出现, 完全平方数会出现奇数个因数
        return int(sqrt(n))


def main():

    sol = Solution()
    n = 3
    assert sol.bulbSwitch(n) == 1
    n = 5
    assert sol.bulbSwitch(n) == 2
    n = 11
    assert sol.bulbSwitch(n) == 3
    n = 999999999
    sol.bulbSwitch(n)


if __name__ == "__main__":
    main()
