"""
https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/608/week-1-july-1st-july-7th/3799/

An n-bit gray code sequence is a sequence of 2n integers where:

Every integer is in the inclusive range [0, 2n - 1],
The first integer is 0,
An integer appears no more than once in the sequence,
The binary representation of every pair of adjacent integers differs by exactly one bit, and
The binary representation of the first and last integers differs by exactly one bit.
Given an integer n, return any valid n-bit gray code sequence.

Constraints:

1 <= n <= 16
"""
from typing import List

class Solution:
    def grayCode(self, n: int) -> List[int]:
        code = [i for i in range(2 ** n)]

        def makeGray(arr: List[int]):
            n = len(arr)
            if n <= 2:
                return arr
            mid = len(arr) // 2
            return makeGray(arr[:mid]) + list(reversed(makeGray(arr[mid:])))

        return makeGray(code)

solution = Solution()
print(solution.grayCode(1)) # [0,1]
print(solution.grayCode(2)) # [0,1,3,2]
print(solution.grayCode(3)) # [0,1,3,2,6,7,5,4]
print(solution.grayCode(8))
print(solution.grayCode(16))
