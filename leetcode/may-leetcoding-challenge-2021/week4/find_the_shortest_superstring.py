"""
https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/601/week-4-may-22nd-may-28th/3753/

Given an array of strings words, return the smallest string that contains each string in words as a substring. If there are multiple valid strings of the smallest length, return any of them.

You may assume that no string in words is a substring of another string in words.

Constraints:

1 <= words.length <= 12
1 <= words[i].length <= 20
words[i] consists of lowercase English letters.
All the strings of words are unique.
"""

class Solution:
    # brute-force: find all permutations -> factorial time -> timeout
    def shortestSuperstring(self, words):
        superstr = None
        
        def make_permutations(words):
          if len(words) == 1:
            return [words]
          ret = []
          w0, *rest = words
          permutations = make_permutations(rest)
          for p in permutations:
            ret.append([w0] + p)
            for i in range(1, len(p)):
              new_p = p[:i] + [w0] + p[i:]
              ret.append(new_p)
            ret.append(p + [w0])
          return ret

        def compress_words(words):
          if len(words) == 1:
            return words[0]
          w0, *rest = words
          merged = compress_words(rest)
          min_len = min(len(w0), len(merged))
          for l in reversed(range(1, min_len + 1)):
            left, right = w0[len(w0)-l:], merged[:l]
            if left == right:
              return w0 + merged[l:]
          return w0 + merged

        permutations = make_permutations(words)
        candidates = list(map(compress_words, permutations))

        for candidate in candidates:
          if superstr is None or len(superstr) > len(candidate):
            superstr = candidate

        return superstr

    # brute-force: dynamic programming
    def shortestSuperstring(self, words):
        N = len(words)

        # Populate overlaps
        overlaps = [[0] * N for _ in range(N)]
        for i, x in enumerate(words):
            for j, y in enumerate(words):
                if i != j:
                    for ans in range(min(len(x), len(y)), -1, -1):
                        if x.endswith(y[:ans]):
                            overlaps[i][j] = ans
                            break

        # dp[mask][i] = most overlap with mask, ending with ith element
        dp = [[0] * N for _ in range(1<<N)]
        parent = [[None] * N for _ in range(1<<N)]
        for mask in range(1, 1 << N):
            for bit in range(N):
                if (mask >> bit) & 1:
                    # Let's try to find dp[mask][bit].  Previously, we had
                    # a collection of items represented by pmask.
                    pmask = mask ^ (1 << bit)
                    if pmask == 0: continue
                    for i in range(N):
                        if (pmask >> i) & 1:
                            # For each bit i in pmask, calculate the value
                            # if we ended with word i, then added word 'bit'.
                            value = dp[pmask][i] + overlaps[i][bit]
                            if value > dp[mask][bit]:
                                dp[mask][bit] = value
                                parent[mask][bit] = i

        # Answer will have length sum(len(A[i]) for i) - max(dp[-1])
        # Reconstruct answer:

        # Follow parents down backwards path that retains maximum overlap
        perm = []
        mask = (1<<N) - 1
        i = max(range(N), key = dp[-1].__getitem__)
        while i is not None:
            perm.append(i)
            mask, i = mask ^ (1<<i), parent[mask][i]

        # Reverse path to get forwards direction; add all remaining words
        perm = perm[::-1]
        seen = [False] * N
        for x in perm:
            seen[x] = True
        perm.extend([i for i in range(N) if not seen[i]])

        # Reconstruct answer given perm = word indices in left to right order
        ans = [words[perm[0]]]
        for i in range(1, len(perm)):
            overlap = overlaps[perm[i-1]][perm[i]]
            ans.append(words[perm[i]][overlap:])

        return "".join(ans)

solution = Solution()
print(solution.shortestSuperstring(["alex","loves","leetcode"])) # "alexlovesleetcode"
print(solution.shortestSuperstring(["catg","ctaagt","gcta","ttca","atgcatc"])) # "gctaagttcatgcatc"
print(solution.shortestSuperstring(["aaabbb", "bbbccc", "cccddd"])) # "aaabbbcccddd"
print(solution.shortestSuperstring(["given","an","array","of","strings","words","return","the"])) # givenanarrayofwordstringsreturnthe
# print(solution.shortestSuperstring(["given","an","array","of","strings","words","return","the","smallest","string","that","contains"])) # ?
print(solution.shortestSuperstring(["gruuz","zjr","uuzj","rfgr"])) # "rfgruuzjr"


