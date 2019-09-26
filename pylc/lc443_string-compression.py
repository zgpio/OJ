# from itertools import combinations
from typing import List
from math import sqrt


class Solution:
    def compress(self, chars: List[str]) -> int:

        chars.append('@@')  # 哨兵
        p = chars[0]
        cnt = 0
        res = []
        # TODO: 原地操作
        for i in chars:
            if i == p:
                cnt += 1
            else:
                res.append(p)
                if cnt > 1:
                    for c in str(cnt):
                        res.append(c)

                p = i
                cnt = 1

        print(res)
        chars[:] = res
        return len(res)


def main():

    sol = Solution()
    chars = ["a", "a", "b", "b", "c", "c", "c"]
    ans = 6
    chars2 = ["a", "2", "b", "2", "c", "3"]
    assert sol.compress(chars) == ans
    assert chars == chars2

    chars = ["a"]
    ans = 1
    assert sol.compress(chars) == ans

    chars = ["a", "b", "b", "b", "b", "b", "b", "b", "b", "b", "b", "b", "b"]
    ans = 4
    assert sol.compress(chars) == ans


if __name__ == "__main__":
    main()
