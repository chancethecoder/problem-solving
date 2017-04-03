#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

struct pos { int y, x; };

const int MAX_N = 50;
const int INF = 1000007;
// const int dy[] = { 0, 1, 0, -1, 0 };
// const int dx[] = { 0, 0, 1, 0, -1 };
const int dy[] = { 0, 0, 1, 0, -1 };
const int dx[] = { 0, 1, 0, -1, 0 };
int N, M;
char map[MAX_N + 1][MAX_N + 1];
int memo[MAX_N + 1][MAX_N + 1][5][4];
pos src, dst[2];

/*
5 5
S....
...C.
..##.
.....
.C...

10 10
S#.C......
....#####.
..........
..........
..........
..........
..........
..........
..........
.........C

5 5
S#.C.
....#
.....
.....
....C
*/

int solve(int y, int x, int k, int c)
{
    if (c == 3) return 0;

    int &ret = memo[y][x][k][c];
    if (ret != -1) return ret;

    ret = INF;

    for (int nk = 1; nk <= 4; nk++)
    {
        if (nk == k) continue;
        int ny = y + dy[nk];
        int nx = x + dx[nk];
        if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        if (map[ny][nx] == '#') continue;

        int nc = c;
        if (map[ny][nx] == 'C')
        {
            int t = (ny == dst[0].y && nx == dst[0].x) ? 1 : 2;
            if (nc == t) continue;
            nc += t;
        }
        ret = min(ret, solve(ny, nx, nk, nc) + 1);
    }

    return ret;
}

int main() {

    cin >> N >> M;
    for (int i = 0, c = 0; i < N; i++)
    {
        cin >> map[i];
        for (int j = 0; j < M; j++)
        {
            if (map[i][j] == 'S')
            {
                src.y = i;
                src.x = j;
            }
            if (map[i][j] == 'C')
            {
                dst[c].y = i;
                dst[c++].x = j;
            }
        }
    }

    memset(memo, -1, sizeof(memo));
    int ans = solve(src.y, src.x, 0, 0);

    cout << (ans == INF ? -1 : ans) << endl;

    return 0;
}
