def solve(p):
    dic = {}
    dicx = {}
    dicy = {}
    for t in p:
        dic[t] = 0
        x, y = t.split()
        dicx[int(x)] = 0
        dicy[int(y)] = 0
    for t in p:
        dic[t] += 1
        x, y = t.split()
        dicx[int(x)] += 1
        dicy[int(y)] += 1

    ret = 0
    for x in dicx.values():
        ret += (x * (x - 1)) / 2
    for x in dicy.values():
        ret += (x * (x - 1)) / 2
    for x in dic.values():
        ret -= (x * (x - 1)) / 2
    return ret

n = int(raw_input())
pairs = []
for i in range(n):
    pairs.append(raw_input())

print(solve(pairs))
