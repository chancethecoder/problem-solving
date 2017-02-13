def solve():
    l, r = 0, max(arr)
    while l <= r:
        m = int((l + r) / 2)
        c = sum(map(lambda x: int(x / m), arr))
        if c >= n:
            l = m + 1
        else:
            r = m - 1
    return r

k, n = map(int, input().split())
arr = []
for _ in range(k): arr.append(int(input()))
print(solve())
