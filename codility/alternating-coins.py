"""
There are N coins, each showing either heads or tails. We would like all the coins to form a sequence of alternating heads and tails. What is the minimum number of coins that must be reversed to achieve this?

Write a function:
function solution(A);
that, given an array A consisting of N integers representing the coins, returns the minimum number of coins that must be reversed. Consecutive elements of array A represent consecutive coins and contain either a 0 (heads) or a 1 (tails).

Examples:

1. Given array A = [1, 0, 1, 0, 1, 1], the function should return 1. After reversing the sixth coin, we achieve an alternating sequence of coins [1, 0, 1, 0, 1, 0].
2. Given array A = [1, 1, 0, 1, 1], the function should return 2. After reversing the first and fifth coins, we achieve an alternating sequence [0, 1, 0, 1, 0].
3. Given array A = [0, 1, 0], the function should return 0. The sequence of coins is already alternating.
4. Given array A = [0, 1, 1, 0], the function should return 2. We can reverse the first and second coins to get the sequence: [1, 0, 1, 0].

Assume that:

N is an integer within the range [1..100];
each element of array A is an integer that can have one of the following values: 0, 1.
In your solution, focus on correctness. The performance of your solution will not be the focus of the assessment.
"""

# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
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


print(solution([1, 0, 1, 0, 1, 1])) # 1
print(solution([1, 1, 0, 1, 1])) # 2
print(solution([0, 1, 0])) # 0
print(solution([0, 1, 1, 0])) # 2