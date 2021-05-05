import heapq

def solve(N):
    h = [int(e) for e in input().split()]

    heapq.heapify(h)

    for i in range(N - 1):
        for item in [int(e) for e in input().split()]:
            heapq.heappushpop(h, item)

    return heapq.heappop(h)

if __name__ == "__main__":
    N = int(input())

    print(solve(N))