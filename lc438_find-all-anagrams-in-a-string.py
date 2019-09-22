from itertools import combinations
from typing import List


class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        pd = {}
        for i in p:
            if i in pd:
                pd[i] += 1
            else:
                pd[i] = 1

        res = []

        sd = {}  # 滑动窗字典
        for i in s[:len(p)]:
            if i in sd:
                sd[i] += 1
            else:
                sd[i] = 1
        if sd == pd:
            res.append(0)

        for i in range(1, len(s) - len(p) + 1):
            pre_k = s[i - 1]
            if sd[pre_k] == 1:
                sd.pop(pre_k)
            else:
                sd[pre_k] -= 1

            k = s[i + len(p) - 1]
            if k in sd:
                sd[k] += 1
            else:
                sd[k] = 1

            if sd == pd:
                res.append(i)

        return res


def main():

    sol = Solution()
    s = "cbaebabacd"
    p = "abc"

    ans = [0, 6]
    assert sol.findAnagrams(s, p) == ans

    s = "abab"
    p = "ab"

    ans = [0, 1, 2]
    assert sol.findAnagrams(s, p) == ans


if __name__ == "__main__":
    main()
