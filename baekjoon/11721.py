'''
def solve(str):
    ret = ""
    for i in range(len(str)):
        ret += str[i]
        if (i % 10) == 9:
            ret += "\n"
    return ret

print(solve(raw_input()))
'''

'''
def solve(str):
    return str if len(str) < 10 else str[0:10] + "\n" + solve(str[10:])

print(solve(raw_input()))
'''
