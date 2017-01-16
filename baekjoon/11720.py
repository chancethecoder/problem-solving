'''
def solve(arr):
    ret = 0
    for x in arr:
        ret += int(x)
    return ret

raw_input()
print(solve(raw_input()))
'''

'''
def solve(arr):
    return 0 if arr == "" else int(arr[0]) + solve(arr[1:])

raw_input()
print(solve(raw_input()))
'''

raw_input()
print(reduce(lambda x, y: int(x) + int(y), raw_input()))
