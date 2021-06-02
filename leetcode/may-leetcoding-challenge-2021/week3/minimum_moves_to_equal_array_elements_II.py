"""
https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/600/week-3-may-15th-may-21st/3748/

Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.

In one move, you can increment or decrement an element of the array by 1.

Test cases are designed so that the answer will fit in a 32-bit integer.

Constraints:

n == nums.length
1 <= nums.length <= 105
-109 <= nums[i] <= 109
"""

class Solution:
    def minMoves2(self, nums):
        nums.sort()
        min_move = 10e9 # inf
        l, r = 0, len(nums) - 1
        while True:
            if l > r: break
            mid = (l + r) // 2
            moves = sum(map(lambda x: abs(x - nums[mid]), nums))
            if moves < min_move:
                min_move = moves
                r = mid - 1
            elif moves > min_move:
                l = mid + 1
            else:
                break
        return min_move

"""
solution = Solution()
print(solution.minMoves2([1,2,3])) # 2
print(solution.minMoves2([1,10,2,9])) # 16
print(solution.minMoves2([1,0,0,8,6])) # 14
"""
