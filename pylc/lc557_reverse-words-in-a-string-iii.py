from itertools import combinations
from typing import List


class Solution:
    def reverseWords(self, s: str) -> str:
        s = s[::-1]
        sl = s.split(' ')
        sl.reverse()

        return ' '.join(sl)


def main():

    sol = Solution()
    inp = "Let's take LeetCode contest"
    ans = "s'teL ekat edoCteeL tsetnoc"
    assert sol.reverseWords(inp) == ans


if __name__ == "__main__":
    main()
