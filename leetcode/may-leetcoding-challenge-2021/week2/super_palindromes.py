"""
https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/599/week-2-may-8th-may-14th/3736/

Let's say a positive integer is a super-palindrome if it is a palindrome, and it is also the square of a palindrome.

Given two positive integers left and right represented as strings, return the number of super-palindromes integers in the inclusive range [left, right].

Constraints:

1 <= left.length, right.length <= 18
left and right consist of only digits.
left and right cannot have leading zeros.
left and right represent integers in the range [1, 10^18 - 1].
left is less than or equal to right.
"""

class Solution:
    # brute-force: iterate and check
    # def superpalindromesInRange(self, left, right):
    #     superpalindromes = []

    #     def sqrt(x):
    #         return int(int(x) ** 0.5)

    #     def is_palindrome(x):
    #         return x == x[::-1]

    #     def is_superpalindrome(n):
    #         return is_palindrome(str(n)) and is_palindrome(str(n ** 2))

    #     for n in range(sqrt(left), sqrt(right) + 1):
    #         if is_superpalindrome(n):
    #             superpalindromes.append(n ** 2)
    #     print(superpalindromes)
    #     return len(superpalindromes)

    # brute-force: make list and find
    def superpalindromesInRange(self, left, right):

        def is_palindrome(x):
            return x == x[::-1]

        def is_superpalindrome_sqrt(x):
            return is_palindrome(x) and is_palindrome(str(int(x) ** 2))

        superpalindromes = []
        queue = [ '1', '2', '3' ]

        while queue:
            curr = queue.pop()

            if int(curr) ** 2 > int(right): continue

            if is_superpalindrome_sqrt(curr):

                if curr not in superpalindromes:
                    superpalindromes.append(curr)

                mid = len(curr) // 2
                curr_left = curr[:mid]
                curr_right = curr[mid:]
                candidates = [
                    curr_left + '0' + curr_right,
                    curr_left + '1' + curr_right,
                    curr_left + '2' + curr_right,
                ]
                queue += candidates

        superpalindromes = list(filter(lambda x: int(x) ** 2 >= int(left), superpalindromes))

        return len(superpalindromes)

"""
solution = Solution()
print(solution.superpalindromesInRange('4', '1000')) # 4
print(solution.superpalindromesInRange('1', '2')) # 1
print(solution.superpalindromesInRange('1', '10000000')) # 13
print(solution.superpalindromesInRange('1', '99999999999')) # 26
print(solution.superpalindromesInRange('1', '9999999999999')) # 39
print(solution.superpalindromesInRange('1', '99999999999999')) # 39
print(solution.superpalindromesInRange('1', '9999999999999999')) # 48
print(solution.superpalindromesInRange('1', '999999999999999999')) # 73
print(solution.superpalindromesInRange('999999999999999999', '999999999999999999')) # 0
print(solution.superpalindromesInRange('38455498359', '999999999999999999')) # 45
print(solution.superpalindromesInRange('1020762146323', '142246798855636')) # 17
"""