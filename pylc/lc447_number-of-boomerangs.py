from itertools import combinations, permutations
from typing import List
from math import sqrt


class Solution:
    def numberOfBoomerangs(self, points: List[List[int]]) -> int:
        d = {}
        for i, j in combinations(points, 2):
            dist = (i[0] - j[0])**2 + (i[1] - j[1])**2
            k = f'{i}{dist}'
            if k in d:
                d[k] += 1
            else:
                d[k] = 1

            k = f'{j}{dist}'
            if k in d:
                d[k] += 1
            else:
                d[k] = 1

        res = 0
        for k, v in d.items():
            if v > 1:
                res += v * (v - 1)
            print(f'{k}: {v}')
        return res


def main():

    sol = Solution()
    ps = [[0, 0], [1, 0], [2, 0]]
    ans = 2
    assert sol.numberOfBoomerangs(ps) == ans
    # [[1,0],[0,0],[2,0]] 和 [[1,0],[2,0],[0,0]]


if __name__ == "__main__":
    main()
