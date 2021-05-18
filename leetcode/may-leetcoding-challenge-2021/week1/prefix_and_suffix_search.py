"""
https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/598/week-1-may-1st-may-7th/3728/

Design a special dictionary which has some words and allows you to search the words in it by a prefix and a suffix.

Implement the WordFilter class:

- WordFilter(string[] words) Initializes the object with the words in the dictionary.
- f(string prefix, string suffix) Returns the index of the word in the dictionary which has the prefix prefix and the suffix suffix. If there is more than one valid index, return the largest of them. If there is no such word in the dictionary, return -1.

Constraints:

- 1 <= words.length <= 15000
- 1 <= words[i].length <= 10
- 1 <= prefix.length, suffix.length <= 10
- words[i], prefix and suffix consist of lower-case English letters only.
- At most 15000 calls will be made to the function f.
"""

class WordFilter:

    def __init__(self, words):
        self.words = words
        self.word_dict = {}

        for i in reversed(range(len(self.words))):
            word = self.words[i]
            if word not in self.word_dict:
                self.word_dict[word] = i

    def f(self, prefix: str, suffix: str) -> int:
        for word in self.word_dict:
            if not word.startswith(prefix): continue
            if not word.endswith(suffix): continue
            return self.word_dict[word]

        return -1