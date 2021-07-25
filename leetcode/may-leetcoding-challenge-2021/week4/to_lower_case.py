"""
https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/601/week-4-may-22nd-may-28th/3754/

Given a string s, return the string after replacing every uppercase letter with the same lowercase letter.

Constraints:

1 <= s.length <= 100
s consists of printable ASCII characters.
"""

class Solution:
    def toLowerCase(self, s: str) -> str:
        return s.lower()

solution = Solution()
print(solution.toLowerCase("here")) # "here"
print(solution.toLowerCase("LOVELY")) # "lovely"
