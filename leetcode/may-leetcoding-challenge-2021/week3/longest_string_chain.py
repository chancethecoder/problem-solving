"""
https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/600/week-3-may-15th-may-21st/3746/

You are given an array of words where each word consists of lowercase English letters.

wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given list of words.

Constraints:

1 <= words.length <= 1000
1 <= words[i].length <= 16
words[i] only consists of lowercase English letters.
"""

class Solution:
    # Dynamic programming
    def longestStrChain(self, words):
        # 1. sort by length of word
        words.sort(key=len)
        memo = [-1] * len(words)

        # 2. DP
        def dp(i):
            if memo[i] != -1: return memo[i]
            memo[i] = 1
            for j in range(i):
                if len(words[j]) != len(words[i]) - 1: continue
                l, r, c = 0, 0, 0
                while True:
                    if l >= len(words[j]) or r >= len(words[i]): break
                    if words[j][l] == words[i][r]:
                        l += 1
                        r += 1
                    else:
                        if c >= 1: break
                        c += 1
                        r += 1
                if l == len(words[j]) and r >= len(words[i]) - 1:
                    memo[i] = max(dp(j) + 1, memo[i])
            return memo[i]

        # 3. Call DP w/iteration
        for i in range(len(words)): dp(i)

        return max(memo)


solution = Solution()
print(solution.longestStrChain(["a","b","ba","bca","bda","bdca"])) # 4
print(solution.longestStrChain(["xbc","pcxbcf","xb","cxbc","pcxbc"])) # 5
print(solution.longestStrChain(["abcd","dbqca"])) # 1
print(solution.longestStrChain(["a","b","ab","bac"])) # 2
