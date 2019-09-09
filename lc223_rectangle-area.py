from itertools import combinations
from typing import List, Tuple


class Solution:
    def computeArea(self, A: int, B: int, C: int, D: int, E: int, F: int,
                    G: int, H: int) -> int:
        def overlap(a: Tuple[int, int], b: Tuple[int, int]):
            """Overlap between two intervals."""
            assert a[0] <= a[1] and b[0] <= b[1]
            L = max(a[1], b[1]) - min(a[0], b[0])
            l = (a[1] - a[0]) + (b[1] - b[0])
            return l - L

        ox = overlap((A, C), (E, G))
        oy = overlap((B, D), (F, H))

        all = (C - A) * (D - B) + (G - E) * (H - F)
        if ox > 0 and oy > 0:
            return all - ox * oy
        else:
            return all


def main():

    sol = Solution()
    assert sol.computeArea(-3, 0, 3, 4, 0, -1, 9, 2) == 45
    assert sol.computeArea(0, 0, 0, 0, -1, -1, 1, 1) == 4


if __name__ == "__main__":
    main()
