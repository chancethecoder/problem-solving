"""
https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/599/week-2-may-8th-may-14th/3738/

Count the number of prime numbers less than a non-negative number, n.

Constraints:

0 <= n <= 5 * 10^6
"""

class Solution:
    # sieve of eratosthenes #1
    def countPrimes(self, n):
        primes = []
        visited = [False] * n

        for x in range(2, n):
            if visited[x]: continue
            visited[x] = True
            primes.append(x)
            for jump in range(x, n, x):
                visited[jump] = True

        return len(primes)

"""
solution = Solution()
print(solution.countPrimes(10)) # 4
print(solution.countPrimes(0)) # 0
print(solution.countPrimes(1)) # 0
print(solution.countPrimes(5 * (10 ** 6))) # 348182
"""
