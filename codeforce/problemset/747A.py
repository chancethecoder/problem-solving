def solve(n):
    r = k = 1
    while k * k <= n:
        if n % k == 0: r = k
        k += 1
    return "%d %d" % (r, n / r)

print(solve(int(input())))
