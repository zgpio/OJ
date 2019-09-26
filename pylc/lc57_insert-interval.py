# from itertools import combinations
from typing import List
from typing import Tuple


class Solution:
    def insert(self, intervals: List[List[int]],
               newInterval: List[int]) -> List[List[int]]:
        def overlap(a: Tuple[int, int], b: Tuple[int, int]):
            """Overlap between two intervals."""
            assert a[0] <= a[1] and b[0] <= b[1]
            L = max(a[1], b[1]) - min(a[0], b[0])
            l = (a[1] - a[0]) + (b[1] - b[0])
            return l - L

        res = []
        tmp = [newInterval]
        for i in intervals:
            if overlap(i, newInterval) < 0:
                res.append(i)
            else:
                tmp.append(i)

        x = [i[0] for i in tmp]
        y = [i[1] for i in tmp]
        ins = [min(x), max(y)]
        res.append(ins)
        # NOTE: sort的排序标准
        # TODO: 插入区间最好能在以上循环中完成, 没有利用区间列表是有序的条件
        res.sort()

        return res


def main():

    sol = Solution()
    inp = [[1, 2], [3, 5], [6, 7], [8, 10], [12, 16]]
    new = [4, 8]
    out = [[1, 2], [3, 10], [12, 16]]
    assert sol.insert(inp, new) == out, out
    inp = [[1, 3], [6, 9]]
    new = [2, 5]
    out = [[1, 5], [6, 9]]
    assert sol.insert(inp, new) == out, out


if __name__ == "__main__":
    main()
