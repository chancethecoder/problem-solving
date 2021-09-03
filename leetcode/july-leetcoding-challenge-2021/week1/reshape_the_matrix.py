"""
https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/608/week-1-july-1st-july-7th/3803/

In MATLAB, there is a handy function called reshape which can reshape an m x n matrix into a new one with a different size r x c keeping its original data.

You are given an m x n matrix mat and two integers r and c representing the number of rows and the number of columns of the wanted reshaped matrix.

The reshaped matrix should be filled with all the elements of the original matrix in the same row-traversing order as they were.

If the reshape operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 100
-1000 <= mat[i][j] <= 1000
1 <= r, c <= 300
"""
from typing import List

class Solution:
    def matrixReshape(self, mat: List[List[int]], r: int, c: int) -> List[List[int]]:
        m = len(mat)
        n = len(mat[0])

        if m * n != r * c:
            return mat

        ans = [[0] * c for _ in range(r)]

        for i in range(m*n):
            ans[i//c][i%c] = mat[i//n][i%n]

        return ans

solution = Solution()
print(solution.matrixReshape([[1,2],[3,4]], 1, 4)) # [[1,2,3,4]]
print(solution.matrixReshape([[1,2],[3,4]], 2, 4)) # [[1,2],[3,4]]
print(solution.matrixReshape([[1,2],[3,4]], 4, 1)) # [[1],[2],[3],[4]]