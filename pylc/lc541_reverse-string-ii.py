# from itertools import combinations
from typing import List
from math import sqrt


class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        n = len(s)
        ls = list(s)
        # NOTE: 尾部的长度为0～2k-1
        for i in range(0, n - (2 * k - 1), 2 * k):
            snip = ls[i:i + k]
            snip.reverse()
            ls[i:i + k] = snip

        rest = n % (2 * k)
        if rest == 0:
            pass
        elif rest > k:
            snip = ls[n - rest:n - rest + k]
            snip.reverse()
            ls[n - rest:n - rest + k] = snip
        else:
            snip = ls[n - rest:]
            snip.reverse()
            ls[n - rest:] = snip
        print(''.join(ls))
        return ''.join(ls)


def main():

    sol = Solution()
    s = "abcdefghfg"
    k = 2
    ans = "bacdfeghgf"
    assert sol.reverseStr(s, k) == ans

    s = "abcd"
    k = 2
    ans = "bacd"
    assert sol.reverseStr(s, k) == ans

    s = "hyzqyljrnigxvdtneasepfahmtyhlohwxmkqcdfehybknvdmfrfvtbsovjbdhevlfxpdaovjgunjqlimjkfnqcqnajmebeddqsgl"
    k = 39
    ans = "fdcqkmxwholhytmhafpesaentdvxginrjlyqzyhehybknvdmfrfvtbsovjbdhevlfxpdaovjgunjqllgsqddebemjanqcqnfkjmi"
    assert sol.reverseStr(s, k) == ans, ans


if __name__ == "__main__":
    main()
