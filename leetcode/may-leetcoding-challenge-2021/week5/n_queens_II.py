"""
https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/602/week-5-may-29th-may-31st/3760/

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.

Constraints:

1 <= n <= 9
"""

class Solution:
    def totalNQueens(self, n):

        def recursion(i, cols, diagonal1, diagonal2):
            if i == n:
                return 1
            else:
                ret = 0
                for j in range(n):
                    if cols[j] or diagonal1[n - 1 - i + j] or diagonal2[i + j]: continue
                    cols[j] = diagonal1[n - 1 - i + j] = diagonal2[i + j] = True
                    ret += recursion(i + 1, cols, diagonal1, diagonal2)
                    cols[j] = diagonal1[n - 1 - i + j] = diagonal2[i + j] = False
                return ret

        cols = [False] * n
        diagonal1 = [False] * (2 * n - 1)
        diagonal2 = [False] * (2 * n - 1)

        return recursion(0, cols, diagonal1, diagonal2)

"""
solution = Solution()
print(solution.totalNQueens(1)) # 1
print(solution.totalNQueens(2)) # 0
print(solution.totalNQueens(3)) # 0
print(solution.totalNQueens(4)) # 2
print(solution.totalNQueens(5)) # 10
print(solution.totalNQueens(6)) # 4
print(solution.totalNQueens(7)) # 40
print(solution.totalNQueens(8)) # 92
print(solution.totalNQueens(9)) # 352
"""
