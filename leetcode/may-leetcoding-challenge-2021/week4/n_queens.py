"""
https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/601/week-4-may-22nd-may-28th/3752/

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

Constraints:

1 <= n <= 9
"""

class Solution:
    # greedy search
    def solveNQueens(self, n):

        def get_possible_n_queens(row, col_covered, lt_diagonal_covered, rt_diagonal_covered, places):
            if row == n:
                board = [['.'] * n for _ in range(n)]
                for r, c in places:
                    board[r][c] = 'Q'
                board = list(map(lambda row: ''.join(row), board))
                return [board]
            ret = []
            for col in range(n):
                lt_idx = (n - 1 - row) + col
                rt_idx = row + col
                if col_covered[col] or lt_diagonal_covered[lt_idx] or rt_diagonal_covered[rt_idx]: continue
                col_covered[col] = lt_diagonal_covered[lt_idx] = rt_diagonal_covered[rt_idx] = True
                places.append((row, col))
                ret += get_possible_n_queens(row + 1, col_covered, lt_diagonal_covered, rt_diagonal_covered, places)
                col_covered[col] = lt_diagonal_covered[lt_idx] = rt_diagonal_covered[rt_idx] = False
                places.pop()
            return ret

        col_covered = [False] * n
        lt_diagonal_covered = [False] * (2 * n - 1)
        rt_diagonal_covered = [False] * (2 * n - 1)

        return get_possible_n_queens(0, col_covered, lt_diagonal_covered, rt_diagonal_covered, [])

"""
solution = Solution()
print(solution.solveNQueens(1))
# [["Q"]]
print(solution.solveNQueens(2))
# []
print(solution.solveNQueens(3))
# []
print(solution.solveNQueens(4))
# [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
# print(solution.solveNQueens(5))
# ?
# print(solution.solveNQueens(9))
# ?
"""
