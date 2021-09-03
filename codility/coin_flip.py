from typing import List

def solution(A: List[int]):
    head_first = 0
    tail_first = 0

    for i in range(len(A)):
        s = i % 2 # 0: even, 1: odd
        if s == 0:
            if A[i] == 1:
                head_first += 1
            else:
                tail_first += 1
        else:
            if A[i] == 0:
                head_first += 1
            else:
                tail_first += 1

    return min(head_first, tail_first)

print(solution([1,0,1,0,1,1])) # 1
print(solution([1,1,0,1,1])) # 2
print(solution([0,1,0])) # 0
print(solution([0,1,1,0])) # 2
