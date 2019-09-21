# from itertools import combinations
from typing import List


# NOTE:
# The length of num is less than 10002 and will be ≥ k.
# The given num does not contain any leading zero.
class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        n = len(num)
        if n == k:
            return '0'
        # NOTE: There is no stack in the python standard library.
        s = []
        for i, c in enumerate(num):

            # 尽可能地移除比c大的栈顶元素
            while len(s) > 0 and c < s[-1] and i - len(s) < k:
                s.pop(-1)  # or del s[-1]

            s.append(c)

        print(str(int(''.join(s[:n - k]))))
        return str(int(''.join(s[:n - k])))


def main():

    sol = Solution()
    num = "1432219"
    k = 3
    assert sol.removeKdigits(num, k) == "1219"

    num = "10200"
    k = 1
    assert sol.removeKdigits(num, k) == "200"

    num = "10"
    k = 2
    assert sol.removeKdigits(num, k) == "0"

    num = "1234560"
    k = 6
    assert sol.removeKdigits(num, k) == "0"
    num = "9"
    k = 1
    assert sol.removeKdigits(num, k) == "0"
    num = "112"
    k = 1
    assert sol.removeKdigits(num, k) == "11"


if __name__ == "__main__":
    main()
