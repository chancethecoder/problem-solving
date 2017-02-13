'''
def solve(str):
    s = []
    ret = 0
    i = 0
    while i < len(str):
        if str[i] == '(':
            s.append(str[i])
            if str[i + 1] == ')':
                # count
                s.pop()
                ret += len(s)
                i += 1
        else:
            # close
            s.pop()
            ret += 1
        i += 1

    return ret

print(solve(input()))
'''

ans = d = i = 0
for c in input():
    j = c < ')' # ( : 1 / ) : 0
    d += 2 * j - 1
    ans += (d - (~(-d) * j)) * i
    i = j
print(ans)
