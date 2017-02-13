def solve(n, k):
    r = 240 - k
    x = 0
    while 0 <= r:
        x += 1
        r -= 5 * x
    return min(x - 1, n)

n, k = map(int, input().split())
print(solve(n, k))
