#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;
const int MAX_N = 100;
const int dy[] = {0, 0, -1, 1};
const int dx[] = {-1, 1, 0, 0};
int n, m;
char map[MAX_N + 1][MAX_N + 1];
int dist[MAX_N][MAX_N];

int solve()
{
    queue<pair<int, int> > q;
    q.push(make_pair(0, 0));
    dist[0][0] = 1;

    while(!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int k = 0; k < 4; ++k)
        {
            int ny = y + dy[k];
            int nx = x + dx[k];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if(map[ny][nx] == '0') continue;
            if(dist[ny][nx] && dist[ny][nx] < dist[y][x] + 1) continue;

            dist[ny][nx] = dist[y][x] + 1;
            q.push(make_pair(ny, nx));
        }
    }
    return dist[n - 1][m - 1];
}

void proc()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i)
    {
        getchar(); scanf("%s", map[i]);
    }
    printf("%d\n", solve());
}

int main()
{
    proc();
    return 0;
}
