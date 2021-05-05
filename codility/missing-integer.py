# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
    # write your code in Python 3.6
    N = len(A)
    F = list(filter(lambda x: x > 0 and x <= N, A))
    max_n = len(F) + 1
    B = [0] * max_n

    for f in F:
        if f > max_n: continue
        B[f] = 1

    for i in range(1, max_n):
        if B[i] == 0:
            return i

    return max_n