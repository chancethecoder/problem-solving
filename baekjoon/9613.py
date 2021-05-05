def solve(arr):
    res = 0

    def gcd(a, b):
        return gcd(b, a % b) if b else a

    for i in range(len(arr) -1):
        for j in range(i + 1, len(arr)):
            res += gcd(arr[i], arr[j])

    return res

if __name__ == "__main__":
    t = int(input())

    for _ in range(t):
        n, *arr = [int(e) for e in input().split()]
        print(solve(arr))