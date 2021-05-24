"""
https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/599/week-2-may-8th-may-14th/3737/

You are given an array target of n integers. From a starting array arr consisting of n 1's, you may perform the following procedure :

let x be the sum of all elements currently in your array.
choose index i, such that 0 <= i < n and set the value of arr at index i to x.
You may repeat this procedure as many times as needed.
Return true if it is possible to construct the target array from arr, otherwise, return false.

Constraints:

n == target.length
1 <= n <= 5 * 10^4
1 <= target[i] <= 10^9
"""
class Solution:
    # brute-force: find biggest and insert iterate loop
    def isPossible(self, target):
        target.sort()

        while True:
            if len(target) == 1: break
            biggest = target[-1]
            rest_sum = sum(target) - biggest

            if biggest <= rest_sum: break
            if rest_sum == 1: return True

            target[-1] %= rest_sum

            if target[-1] == 0: return False

            target.sort()

        return True if sum(target) == len(target) else False

"""
solution = Solution()
print(solution.isPossible([9,3,5])) # True
print(solution.isPossible([1])) # True
print(solution.isPossible([8,5])) # True
print(solution.isPossible([1,4,1,1])) # True
print(solution.isPossible([1,7,1,1])) # True
print(solution.isPossible([1,1000000000])) # True

print(solution.isPossible([2])) # False
print(solution.isPossible([1,1,1,2])) # False
print(solution.isPossible([15,17,19])) # False
print(solution.isPossible([1,8,1,1])) # False
print(solution.isPossible([2,900000002])) # False
"""

"""
import random
ones = [1 for _ in range(5 * (10 ** 4))]
shuffle_count = 1000

for _ in range(shuffle_count):
    rand_idx = random.randrange(0,len(ones))
    ones[rand_idx] = sum(ones)

print(ones)
"""
