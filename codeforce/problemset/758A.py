from functools import reduce

input()
a = list(map(int, input().split()))
print(max(a) * len(a) - reduce(lambda x, y: x + y, a))
