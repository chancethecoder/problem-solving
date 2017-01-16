queue = []

def push(e):
    queue.append(e)

def pop():
    return -1 if empty() else queue.pop(0)

def front():
    return -1 if empty() else queue[0]

def back():
    return -1 if empty() else queue[len(queue) - 1]

def size():
    return len(queue)

def empty():
    return 1 if size() <= 0 else 0

N = int(raw_input())
for i in range(N):
    line = raw_input()
    if line[:2] == "pu":
        push(line.split()[1])
    elif line[:1] == "p":
        print(pop())
    elif line[:1] == "f":
        print(front())
    elif line[:1] == "b":
        print(back())
    elif line[:1] == "s":
        print(size())
    elif line[:1] == "e":
        print(empty())
