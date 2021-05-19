"""
https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/598/week-1-may-1st-may-7th/3734/

Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string.

Constraints:

1 <= word1.length, word2.length <= 500
word1 and word2 consist of only lowercase English letters.
"""

# class Solution:
#     def minDistance(self, word1, word2):
#         if word1 == '' or word2 == '':
#             return 1

#         longer, shorter = (word1, word2) if len(word1) > len(word2) else (word2, word1)

#         if shorter in longer:
#             return len(longer) - len(shorter)

#         return min(self.minDistance(longer[1:], shorter) + 1, self.minDistance(longer[0:-1], shorter) + 1)

# class Solution:
#     def minDistance(self, word1, word2):
#         # word1 search
#         from_left = []
#         left, right = (0, 0)
#         while left < len(word1) and right < len(word2):
#             if word1[left] == word2[right]:
#                 from_left.append(word1[left])
#                 left += 1
#                 right += 1
#             else:
#                 left += 1

#         print(f'from_left: {from_left}')

#         # word2 search
#         from_right = []
#         left, right = (0, 0)
#         while left < len(word1) and right < len(word2):
#             if word1[left] == word2[right]:
#                 from_right.append(word2[right])
#                 left += 1
#                 right += 1
#             else:
#                 right += 1

#         print(f'from_right: {from_right}')

#         sub_len = max(len(from_left), len(from_right))

#         return len(word1) + len(word2) - (sub_len * 2)

class Solution:
    # LCS Algorithm
    def minDistance(self, word1, word2):
        memo = [[0] * 501 for _ in range(501)]
        for i in range(len(word1)):
            for j in range(len(word2)):
                if word1[i] == word2[j]:
                    memo[i+1][j+1] = memo[i][j] + 1
                else:
                    memo[i+1][j+1] = max(memo[i+1][j], memo[i][j+1])
        return len(word1) + len(word2) - (2 * memo[len(word1)][len(word2)])

"""
solution = Solution()
print(solution.minDistance('sea', 'eat')) # 2
print(solution.minDistance('leetcode', 'etco')) # 4
print(solution.minDistance('x', 'etco')) # 5
print(solution.minDistance('sea', 'ate')) # 4
print(solution.minDistance('park', 'spake')) # 3
print(solution.minDistance('kitten', 'sitting')) # 5
print(solution.minDistance('intention', 'execution')) # 8
print(solution.minDistance('abcdxabcde', 'abcdeabcdx')) # 4
print(solution.minDistance('rxsqwxvofiwklxisvzdheasbczkltcjzslbovpsaqewoggxtcmjoqxsialugufydfetarflfzsskgfjnafqlqdi', 'sxolsazosiaf')) # 75
"""