"""
https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/599/week-2-may-8th-may-14th/3739/

There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

Constraints:

1 <= cardPoints.length <= 10^5
1 <= cardPoints[i] <= 10^4
1 <= k <= cardPoints.length
"""

class Solution:
    # brute-force: iteration
    def maxScore(self, cardPoints, k):
        total_score = sum(cardPoints)
        n = len(cardPoints)
        sub_len = n - k

        # find smallest score of subarray with n - k elements
        subarray_score = sum(cardPoints[:sub_len])
        max_score = total_score - subarray_score
        for i in range(1, k + 1):
            subarray_score -= cardPoints[i - 1]
            subarray_score += cardPoints[sub_len + i - 1]
            max_score = max(max_score, total_score - subarray_score)

        return max_score


solution = Solution()
print(solution.maxScore([1,2,3,4,5,6,1], 3)) # 12
print(solution.maxScore([2, 2, 2], 2)) # 4
print(solution.maxScore([8], 1)) # 8
print(solution.maxScore([9,7,7,9,7,7,9], 7)) # 55
print(solution.maxScore([1,1000,1], 1)) # 1
print(solution.maxScore([1,79,80,1,1,1,200,1], 3)) # 202
print(solution.maxScore([96,90,41,82,39,74,64,50,30], 8)) # 536

