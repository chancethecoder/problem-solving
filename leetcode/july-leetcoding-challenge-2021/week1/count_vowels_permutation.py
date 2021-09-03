"""
https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/608/week-1-july-1st-july-7th/3802/

Given an integer n, your task is to count how many strings of length n can be formed under the following rules:

Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
Each vowel 'a' may only be followed by an 'e'.
Each vowel 'e' may only be followed by an 'a' or an 'i'.
Each vowel 'i' may not be followed by another 'i'.
Each vowel 'o' may only be followed by an 'i' or a 'u'.
Each vowel 'u' may only be followed by an 'a'.
Since the answer may be too large, return it modulo 10^9 + 7.

Constraints:

1 <= n <= 2 * 10^4
"""

class Solution:
    def countVowelPermutation(self, n: int) -> int:
        count = [[0] * 5 for _ in range(20001)]
        mod = 10 ** 9 + 7
        
        count[1][0] = 1 # a
        count[1][1] = 1 # e
        count[1][2] = 1 # i
        count[1][3] = 1 # o
        count[1][4] = 1 # u

        for i in range(2, 20001):
            count[i][0] = count[i-1][1]
            count[i][1] = (count[i-1][0] + count[i-1][2]) % mod
            count[i][2] = (count[i-1][0] + count[i-1][1] + count[i-1][3] + count[i-1][4]) % mod
            count[i][3] = (count[i-1][2] + count[i-1][4]) % mod
            count[i][4] = count[i-1][0]

        return sum(count[n]) % mod

solution = Solution()
print(solution.countVowelPermutation(1)) # 5
print(solution.countVowelPermutation(2)) # 10
print(solution.countVowelPermutation(5)) # 68
print(solution.countVowelPermutation(144)) # 18208803
print(solution.countVowelPermutation(20000)) # ?
