"""
https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/601/week-4-may-22nd-may-28th/3758/

You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements.

Return the maximum score you can get by erasing exactly one subarray.

An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).
 
Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^4
"""
from collections import deque

class Solution:
    def maximumUniqueSubarray(self, nums):
        idx = 0
        max_sum = nums[0]
        uniqueset = [nums[0]]
        numset = [False] * 10001
        numset[nums[0]] = True

        while idx < len(nums) - 1:
            if not numset[nums[idx+1]]:
                uniqueset.append(nums[idx+1])
                numset[nums[idx+1]] = True
                idx += 1
                max_sum = max(max_sum, sum(uniqueset))
            else:
                while uniqueset:
                    x = uniqueset.pop(0)
                    numset[x] = False
                    if x == nums[idx+1]: break
        return max_sum

"""
solution = Solution()
print(solution.maximumUniqueSubarray([4,2,4,5,6])) # 17
print(solution.maximumUniqueSubarray([5,2,1,2,5,2,1,2,5])) # 8
print(solution.maximumUniqueSubarray([10])) # 10
print(solution.maximumUniqueSubarray([-1,-1,-1])) # -1
print(solution.maximumUniqueSubarray(list(range(1000)))) # 499500
print(solution.maximumUniqueSubarray(list(range(10000)))) # 49950000
print(solution.maximumUniqueSubarray([e % 10000 for e in range(100000)])) # 49950000
"""
