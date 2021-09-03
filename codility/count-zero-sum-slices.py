"""
CountZeroSumSlices

Write a function solution that, given an array A consisting of N integers, returns the number of fragments of A whose sum equals 0 (that is, pairs (P, Q) such that P ≤ Q and the sum A[P] + A[P+1] + ... + A[Q] is 0). The function should return −1 if this number exceeds 1,000,000,000.

Examples:

1. Given A = [2, −2, 3, 0, 4, −7], the function should return 4, as explained on this picture:

Intervals with sum 0: [2, -2], [3, 0, 4, -7], [0], [2, -2, 3, 0, 4, -7]

2. Given A = [0, 0, ..., 0] of length 100,000, the function should return −1.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [−10,000..10,000].
"""

# O(n^2)
# def solution(A):
#     ret = 0
#     for p in range(len(A)):
#         sum = 0
#         for q in range(p,len(A)):
#             sum += A[q]
#             if sum == 0:
#                 ret += 1
#                 if ret > 1000000000:
#                     return -1
#     return ret

# O(n)
def solution(A):
    ret = 0
    sum = 0
    hash = {}
    hash[0] = 1
    for i in range(len(A)):
        sum += A[i]
        if sum in hash:
            ret += hash[sum]
        else:
            hash[sum] = 0
        hash[sum] = hash[sum] + 1
    return ret if ret <= 1000000000 else -1

print(solution([2,-2,3,0,4,-7])) # 4
print(solution([0]*1000)) # 500500
print(solution([0]*10000)) # 50005000
print(solution([0]*100000)) # 5000050000