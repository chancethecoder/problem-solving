'''
mod = 10007
n, k = map(int, input().split())
arr = [[0] * (n + 1)] * 2

for i in range(1, n + 1):
    for j in range(i + 1):
        if j == 0 or j == i:
            arr[1][j] = 1
        else:
            arr[1][j] = (arr[0][j] + arr[0][j - 1]) % mod
    arr[0] = list(arr[1])

print(arr[0][k])
'''

def solve(n, k):
    row = [1]
    for _ in range(n):
        row = [1] + [sum(pair) for pair in zip(row, row[1:])] + [1]
    return row[k] % 10007

n, k = map(int, input().split())
print(solve(n, k))
