# from itertools import combinations
from typing import List


class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        L = len(matrix)
        X = L // 2
        for x in range(X + 1):
            l = L - x * 2
            for b in range(l - 1):
                t = matrix[x][x + b]
                matrix[x][x + b] = matrix[x + l - 1 - b][x]
                matrix[x + l - 1 - b][x] = matrix[x + l - 1][x + l - 1 - b]
                matrix[x + l - 1][x + l - 1 - b] = matrix[x + b][x + l - 1]
                matrix[x + b][x + l - 1] = t
        print("predict:", matrix)


# python lc48_rotate-image.py < input/pylc48
def main():

    n_lst = []
    # k case; n_lst is matrix order list of k case
    k, *n_lst = list(map(int, input().split()))
    print(k, n_lst)
    sol = Solution()
    for case in range(k):
        test = []
        order = n_lst[case]
        for _ in range(order):
            test.append(list(map(int, input().split())))

        ans = []
        for _ in range(order):
            ans.append(list(map(int, input().split())))
        print(test, ans)
        sol.rotate(test)
        assert test == ans


if __name__ == "__main__":
    main()
