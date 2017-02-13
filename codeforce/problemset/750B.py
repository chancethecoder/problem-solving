def solve():
    y = 0
    for _ in range(int(input())):
        l, d = input().split()
        l = int(l)
        if y == 0 and d[0] != 'S': return "NO"
        if y == 20000 and d[0] != 'N': return "NO"

        if d[0] in ['E', 'W']: continue

        y += l if d[0] == 'S' else -l
        if y < 0 or y > 20000: return "NO"

    return "NO" if y else "YES"

print(solve())
