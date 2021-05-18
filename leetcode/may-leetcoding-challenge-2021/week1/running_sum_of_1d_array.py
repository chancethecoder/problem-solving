"""
https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/598/week-1-may-1st-may-7th/3730/

Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

Return the running sum of nums.

Constraints:

1 <= nums.length <= 1000
-10^6 <= nums[i] <= 10^6
"""

class Solution:
    def runningSum(self, nums):
        sumArray = [0] * len(nums)
        for i in range(len(nums)):
            sumArray[i] = nums[i]
            if i != 0: sumArray[i] += sumArray[i - 1]
        return sumArray