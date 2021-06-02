"""
https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/600/week-3-may-15th-may-21st/3750/

Given a list of strings words and a string pattern, return a list of words[i] that match pattern. You may return the answer in any order.

A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.

Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.

Constraints:

1 <= pattern.length <= 20
1 <= words.length <= 50
words[i].length == pattern.length
pattern and words[i] are lowercase English letters.
"""

class Solution:
    # brute-force: solve using dictionary
    def findAndReplacePattern(self, words, pattern):
        ans = []
        for word in words:
            permutation_dict = {}
            is_match = True
            for i in range(len(word)):
                letter = word[i]
                if letter not in permutation_dict and pattern[i] not in permutation_dict.values():
                    permutation_dict[letter] = pattern[i]
                elif letter in permutation_dict and permutation_dict[letter] is pattern[i]:
                    continue
                else:
                    is_match = False
            if is_match:
                ans.append(word)
        return ans

solution = Solution()
print(solution.findAndReplacePattern(["abc","deq","mee","aqq","dkd","ccc"], "abb")) # ["mee","aqq"]
print(solution.findAndReplacePattern(["a","b","c"], "a")) # ["a","b","c"]
