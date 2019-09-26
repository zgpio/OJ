# from itertools import combinations
from typing import List


class Solution:
    def checkRecord(self, s: str) -> bool:
        '''
        如果一个学生的出勤记录中不超过一个'A'(缺勤)并且不超过两个连续的'L'(迟到),
        那么这个学生会被奖赏。
        '''
        if s.count('A') > 1:
            return False

        if s.count('LLL') > 0:
            return False

        return True


def main():

    sol = Solution()
    inp = "PPALLP"
    ans = True
    assert sol.checkRecord(inp) == ans

    inp = "PPALLL"
    ans = False
    assert sol.checkRecord(inp) == ans


if __name__ == "__main__":
    main()
