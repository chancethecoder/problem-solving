"""
https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/598/week-1-may-1st-may-7th/3732/

Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.

Constraints:

1 <= nums.length <= 1000
0 <= nums[i] <= 105
"""

class Solution:
    def jump(self, nums):
        INF = 1e10
        nums_length = len(nums)
        memo = [INF] * nums_length
        memo[0] = 0
        for i in range(nums_length):
            max_range = nums[i]
            for j in range(1, max_range + 1):
                jump_idx = i + j
                if jump_idx >= nums_length: continue
                memo[jump_idx] = min(memo[jump_idx], memo[i] + 1)
        return memo[-1]

"""
solution = Solution()
print(solution.jump([2,3,1,1,4])) # 2
print(solution.jump([2,3,0,1,4])) # 2
print(solution.jump([0])) # 0
print(solution.jump([1,0])) # 1
"""