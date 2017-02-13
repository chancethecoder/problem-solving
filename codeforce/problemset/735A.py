def solve(s, k):
    i = min(s.index('G'), s.index('T')) + k
    while i < len(s):
        if s[i] == '#': return "NO"
        if s[i] in ['G', 'T']: return "YES"
        i += k
    return "NO"

n, k = map(int, input().split())
print(solve(input(), k))
