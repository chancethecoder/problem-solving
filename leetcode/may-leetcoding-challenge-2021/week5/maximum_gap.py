"""
https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/602/week-5-may-29th-may-31st/3761/

Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.

You must write an algorithm that runs in linear time and uses linear extra space.

Constraints:

1 <= nums.length <= 10^4
0 <= nums[i] <= 10^9
"""

# Using Pigeonhole Sort
# https://en.wikipedia.org/wiki/Pigeonhole_sort
# https://www.geeksforgeeks.org/maximum-adjacent-difference-array-sorted-form/
class Solution:
    def maximumGap(self, nums):
        INF = float('inf')

        if len(nums) < 2:
            return 0
        else:
            n = len(nums)
            max_num = max(nums)
            min_num = min(nums)
            max_bucket = [-INF] * (n + 1)
            min_bucket = [INF] * (n + 1)
            delta = (max_num - min_num) / (n - 1) # expected gap of every bucket

            if delta == 0:
                return 0

            for i in range(n):
                idx = int((nums[i] - min_num) / delta)
                max_bucket[idx] = max(max_bucket[idx], nums[i])
                min_bucket[idx] = min(min_bucket[idx], nums[i])

            prev_val, max_gap = min_num, 0

            for i in range(n):
                if min_bucket[i] == INF:
                    continue                
                max_gap = max(max_gap, min_bucket[i] - prev_val)
                prev_val = max_bucket[i]

        return max_gap

solution = Solution()
print(solution.maximumGap([3,6,9,1])) # 3
print(solution.maximumGap([10])) # 0
print(solution.maximumGap([i % (10 ** 9 + 1) for i in range(10000)])) # 1
print(solution.maximumGap([1,3,100])) # 97
print(solution.maximumGap([1,10000000])) # 9999999
print(solution.maximumGap([1,1,1,1])) # 0
print(solution.maximumGap([1,1,1,1,1,5,5,5,5,5])) # 4
print(solution.maximumGap([15252,16764,27963,7817,26155,20757,3478,22602,20404,6739,16790,10588,16521,6644,20880,15632,27078,25463,20124,15728,30042,16604,17223,4388,23646,32683,23688,12439,30630,3895,7926,22101,32406,21540,31799,3768,26679,21799,23740])) # 2901