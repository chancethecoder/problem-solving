"""
https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/599/week-2-may-8th-may-14th/3740/

Given a 2D matrix matrix, handle multiple queries of the following type:

Calculate the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
Implement the NumMatrix class:

NumMatrix(int[][] matrix) Initializes the object with the integer matrix matrix.
int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 200
-10^5 <= matrix[i][j] <= 10^5
0 <= row1 <= row2 < m
0 <= col1 <= col2 < n
At most 10^4 calls will be made to sumRegion.
"""

class NumMatrix:

    def __init__(self, matrix):
        self.sumTable = [[0] * len(matrix[0]) for _ in range(len(matrix))]
        self.sumTable[0][0] = matrix[0][0]

        for i in range(1, len(matrix[0])):
            self.sumTable[0][i] = matrix[0][i] + self.sumTable[0][i - 1]

        for i in range(1, len(matrix)):
            self.sumTable[i][0] = matrix[i][0] + self.sumTable[i - 1][0]

        for i in range(1, len(matrix)):
            for j in range(1, len(matrix[0])):
                self.sumTable[i][j] = matrix[i][j] + self.sumTable[i - 1][j] + self.sumTable[i][j - 1] - self.sumTable[i - 1][j - 1]

    def sumRegion(self, row1, col1, row2, col2):
        lower_right = self.sumTable[row2][col2]
        upper_right = self.sumTable[row1 - 1][col2] if row1 > 0 else 0
        lower_left = self.sumTable[row2][col1 - 1] if col1 > 0 else 0
        upper_left = self.sumTable[row1 - 1][col1 - 1] if row1 > 0 and col1 > 0 else 0
        return lower_right + upper_left - upper_right - lower_left

"""
numMatrix = NumMatrix([[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]])
print(numMatrix.sumRegion(2, 1, 4, 3)) # 8 (i.e sum of the red rectangle)
print(numMatrix.sumRegion(1, 1, 2, 2)) # 11 (i.e sum of the green rectangle)
print(numMatrix.sumRegion(1, 2, 2, 4)) # 12 (i.e sum of the blue rectangle)
print(numMatrix.sumRegion(0, 0, 0, 0)) # 3
print(numMatrix.sumRegion(4, 4, 4, 4)) # 5
"""

"""
numMatrix = NumMatrix([[3]])
print(numMatrix.sumRegion(0, 0, 0, 0)) # 3
"""
