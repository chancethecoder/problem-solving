def solve(n):
    for x in range(n / 3 + 1):
        if (n - x * 3) % 5 == 0:
            return x + (n - x * 3) / 5
    return -1
    
N = int(raw_input())
print(solve(N))
