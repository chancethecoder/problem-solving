def is2Square(n):
    if n == 1 or n == 2: return True
    return False if n % 2 != 0 else is2Square(n / 2)

def solve(n):
    if is2Square(n):
        return "IMPOSSIBLE"
    elif n % 2 == 1:
        return "%d = %d + %d" % (n, n / 2, n / 2 + 1)
    else:
        k = 2
        while k * (k + 1) <= 2 * n:
            x = int(n / k - (k - 1) / 2)
            if 2 * k * x + (k - 1) * k == 2 * n:
                ret = "%d = " % n
                for i in range(x, x + k - 1):
                    ret += "%d + " % i
                ret += "%d" % (x + k - 1)
                return ret
            k += 1

T = int(input())
for i in range(T):
    print(solve(int(input())))
