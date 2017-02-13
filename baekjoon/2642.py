def find(x):
    arr = [
        [[1, 0, 0, 0], [1, 1, 1, 1], [1, 0, 0, 0]],
        [[1, 0, 0, 0], [1, 1, 1, 1], [0, 1, 0, 0]],
        [[1, 0, 0, 0], [1, 1, 1, 1], [0, 0, 1, 0]],
        [[1, 0, 0, 0], [1, 1, 1, 1], [0, 0, 0, 1]],
        [[0, 1, 0, 0], [1, 1, 1, 1], [0, 1, 0, 0]],
        [[0, 1, 0, 0], [1, 1, 1, 1], [0, 0, 1, 0]],
        [[1, 0, 0, 0], [1, 1, 1, 0], [0, 0, 1, 1]],
        [[0, 1, 0, 0], [1, 1, 1, 0], [0, 0, 1, 1]],
        [[0, 0, 1, 0], [1, 1, 1, 0], [0, 0, 1, 1]],
        [[1, 1, 0, 0], [0, 1, 1, 0], [0, 0, 1, 1]],
        [[1, 1, 1, 0, 0], [0, 0, 1, 1, 1]]
    ]

    d = [
        [2, 0], [0, 2], [-2, 0], [0, -2],
        [2, -1], [2, 1], [1, 2], [-1, 2], [-2, 1], [-2, -1], [-1, -2], [1, -2]
    ]

    for y in arr:
        if len(y) != len(x): continue
        summ = 0
        for i in range(len(x)):
            for j in range(min(len(y[i]), len(x[i]))):
                summ += x[i][j] * y[i][j]
        if summ < 21: continue

        print('------')
        print(y)
        print('------')
        for i in range(len(x)):
            if 1 not in x[i]: continue
            j = x[i].index(1)

            for p in d:
                ny = i + p[1]
                nx = j + p[0]
                if ny < 0 or ny >= len(x): continue
                if nx < 0 or nx >= len(x[i]): continue
                if x[ny][nx] != 0:
                    return x[ny][nx]

    return 0

def solve(x):
    while x[0] == [0] * 6: x = x[1:]
    while x[-1] == [0] * 6: x = x[:-1]

    l, r = 5, 0
    for row in x:
        for i in range(6):
            if row[i] == 0: continue
            l, r = min(l, i), max(r, i)

    x = list(map(lambda row: row[l:r + 1], x))

    if (r - l) < len(x):
        x = list(map(list, zip(*x)))

    y = list(map(lambda r: r[::-1], x))

    ret = 0
    ret = find(x) or find(y)
    return ret

matrix = []
for _ in range(6): matrix.append([int(x) for x in input().split()])
print(solve(matrix))

'''
0 0 0 0 0 0
0 0 0 0 0 0
0 0 5 0 0 0
0 1 2 3 4 0
0 0 6 0 0 0
0 0 0 0 0 0

0 0 0 0 0 0
0 0 4 0 0 0
0 0 5 0 0 0
0 1 2 3 0 0
0 0 6 0 0 0
0 0 0 0 0 0

0 0 0 0 0 0
0 0 0 0 0 0
0 0 5 0 0 0
0 1 2 3 0 0
0 0 0 6 4 0
0 0 0 0 0 0

0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 2 0 0
0 6 5 3 0 0
1 4 0 0 0 0
0 0 0 0 0 0

0 0 0 0 0 0
0 5 0 0 0 0
0 4 3 0 0 0
0 0 1 2 0 0
0 0 0 6 0 0
0 0 0 0 0 0

0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 5 0 0
0 0 3 2 1 0
0 4 6 0 0 0
0 0 0 0 0 0

0 0 0 0 0 0
0 0 0 4 5 2
0 1 3 6 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0

0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 3 2 1 5
0 4 6 0 0 0
0 0 0 0 0 0

0 0 0 0 0 0
0 0 0 4 0 0
0 0 0 6 0 0
0 0 2 1 0 0
0 0 3 0 0 0
0 0 5 0 0 0

0 0 0 4 0 0
0 0 0 0 0 0
0 0 0 6 0 0
0 0 2 1 0 0
0 0 3 0 0 0
0 0 5 0 0 0
'''
