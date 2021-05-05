import sys
import heapq

input = sys.stdin.readline
INF = sys.maxsize

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

def solve(graph, N, M, root, stopover, destination):
    res = INF

    # get shortest path candidates using BFS
    def bfs(graph, src, dest, src_dir):
        queue = []
        visited = [[[False for _ in range(4)] for _ in range(M)] for _ in range(N)]
        candidates = []

        # node: x, y, dist, last_dir
        src_node = (src[0], src[1], 0, src_dir)
        queue.append(src_node)

        while queue:
            x, y, dist, last_dir = queue.pop(0)

            if visited[y][x][last_dir]: continue

            # save visited to pruning
            visited[y][x][last_dir] = True

            # can't pass this way
            if graph[y][x] == '#': continue

            # destination found
            # save results
            if (x, y) == dest:
                heapq.heappush(candidates, (dist, last_dir))

            for idx in range(4):
                # can't move same direction twice
                if idx == last_dir: continue

                next_x = x + dx[idx]
                next_y = y + dy[idx]

                # graph boundary check
                if next_x >= M or next_x < 0 or next_y >= N or next_y < 0: continue

                queue.append((next_x, next_y, dist + 1, idx))

        return candidates

    # calculate minimum
    candidates_rtos = bfs(classroom, root, stopover, -1)
    if not candidates_rtos:
        return INF

    for root_to_stopover, last_dir in candidates_rtos:
        candidates_stod = bfs(classroom, stopover, destination, last_dir)

        if not candidates_stod:
            return INF

        for stopover_to_destination, _ in candidates_stod:
            res = min(res, root_to_stopover + stopover_to_destination)

    return res

if __name__ == "__main__":
    N, M = map(int, input().split())
    classroom = []
    root = (0, 0)
    targets = []

    for _ in range(N):
        classroom.append(list(input()))

    # Find start, target points
    for i in range(N):
        for j in range(M):
            if (classroom[i][j] == 'S'):
                root = (j, i)
            if (classroom[i][j] == 'C'):
                targets.append((j, i))

    rt0t1 = solve(classroom, N, M, root, targets[0], targets[1])
    rt1t0 = solve(classroom, N, M, root, targets[1], targets[0])
    res = min(rt0t1, rt1t0)
    res = -1 if res == INF else res
    print(res)