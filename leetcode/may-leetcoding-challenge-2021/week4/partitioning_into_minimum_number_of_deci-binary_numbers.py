"""
https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/601/week-4-may-22nd-may-28th/3756/

A decimal number is called deci-binary if each of its digits is either 0 or 1 without any leading zeros. For example, 101 and 1100 are deci-binary, while 112 and 3001 are not.

Given a string n that represents a positive decimal integer, return the minimum number of positive deci-binary numbers needed so that they sum up to n.

Constraints:

1 <= n.length <= 105
n consists of only digits.
n does not contain any leading zeros and represents a positive integer.
"""

class Solution:
    def minPartitions(self, n):
        ans = 0
        for c in n:
            if int(c) > ans:
                ans = int(c)
        return ans

solution = Solution()
print(solution.minPartitions("32")) # 3
print(solution.minPartitions("82734")) # 8
print(solution.minPartitions("27346209830709182346")) # 9
