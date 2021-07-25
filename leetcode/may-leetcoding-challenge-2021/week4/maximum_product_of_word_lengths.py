"""
https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/601/week-4-may-22nd-may-28th/3757/

Given a string array words, return the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. If no such two words exist, return 0.

Constraints:

2 <= words.length <= 1000
1 <= words[i].length <= 1000
words[i] consists only of lowercase English letters.
"""

class Solution:
    def maxProduct(self, words):
        memo = [-1] * len(words)

        def has_common(word1, word2):
            return any([c in word1 for c in word2])

        def dp(words):
            if len(words) == 2:
                return 0 if has_common(words[0], words[1]) else len(words[0]) * len(words[1])

            if memo[len(words) - 1] != -1:
                return memo[len(words) - 1]

            left, *rest = words
            memo[len(words) - 1] = dp(rest)
            for right in rest:
                if not has_common(left, right):
                    memo[len(words) - 1] = max(memo[len(words) - 1], len(left) * len(right))
            return memo[len(words) - 1]

        return dp(words)

"""
solution = Solution()
print(solution.maxProduct(["abcw","baz","foo","bar","xtfn","abcdef"])) # 16
print(solution.maxProduct(["a","ab","abc","d","cd","bcd","abcd"])) # 4
print(solution.maxProduct(["a","aa","aaa","aaaa"])) # 0
print(solution.maxProduct(["aaaa"] * 700)) # 0
"""
