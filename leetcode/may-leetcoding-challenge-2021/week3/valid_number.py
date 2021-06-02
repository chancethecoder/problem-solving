"""
https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/600/week-3-may-15th-may-21st/3744/

A valid number can be split up into these components (in order):

A decimal number or an integer.
(Optional) An 'e' or 'E', followed by an integer.
A decimal number can be split up into these components (in order):

(Optional) A sign character (either '+' or '-').
One of the following formats:
At least one digit, followed by a dot '.'.
At least one digit, followed by a dot '.', followed by at least one digit.
A dot '.', followed by at least one digit.
An integer can be split up into these components (in order):

(Optional) A sign character (either '+' or '-').
At least one digit.

For example, all the following are valid numbers: ["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"], while the following are not valid numbers: ["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"].

Given a string s, return true if s is a valid number.

Constraints:

1 <= s.length <= 20
s consists of only English letters (both uppercase and lowercase), digits (0-9), plus '+', minus '-', or dot '.'
"""
import re

class Solution:
    def isNumber(self, s):
        p = re.compile(r'[+-]?(\.[0-9]+|[0-9]+\.[0-9]+|[0-9]+\.|[0-9]+)([eE]{1}[+-]?[0-9]+)?')
        m = p.match(s)
        if m is None:
            return False
        return m.group() is s

"""
solution = Solution()
print(solution.isNumber('2')) # True
print(solution.isNumber('.1')) # True
print(solution.isNumber('2')) # True
print(solution.isNumber('0089')) # True
print(solution.isNumber('-0.1')) # True
print(solution.isNumber('+3.14')) # True
print(solution.isNumber('4.')) # True
print(solution.isNumber('-.9')) # True
print(solution.isNumber('2e10')) # True
print(solution.isNumber('-90E3')) # True
print(solution.isNumber('3e+7')) # True
print(solution.isNumber('+6e-1')) # True
print(solution.isNumber('53.5e93')) # True
print(solution.isNumber('-123.456e789')) # True
print('--------------------')
print(solution.isNumber('abc')) # False
print(solution.isNumber('1a')) # False
print(solution.isNumber('1e')) # False
print(solution.isNumber('e3')) # False
print(solution.isNumber('99e2.5')) # False
print(solution.isNumber('--6')) # False
print(solution.isNumber('-+3')) # False
print(solution.isNumber('95a54e53')) # False
print(solution.isNumber('e')) # False
print(solution.isNumber('.')) # False
print(solution.isNumber('6+1')) # False
"""
