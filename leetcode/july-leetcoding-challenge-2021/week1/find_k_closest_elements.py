"""
https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/608/week-1-july-1st-july-7th/3800/

Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b

Constraints:

1 <= k <= arr.length
1 <= arr.length <= 10^4
arr is sorted in ascending order.
-10^4 <= arr[i], x <= 10^4
"""

from typing import List

class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        ans = arr[:]
        while len(ans) > k:
            a, b = ans[0], ans[-1]
            if abs(a - x) < abs(b - x):
                ans = ans[:-1]
            elif abs(a - x) > abs(b - x):
                ans = ans[1:]
            elif a < b:
                ans = ans[:-1]
            else:
                ans = ans[1:]
        return ans

solution = Solution()
print(solution.findClosestElements([1,2,3,4,5], 4, 3))
print(solution.findClosestElements([1,2,3,4,5], 4, -1))
