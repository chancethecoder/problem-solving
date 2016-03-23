#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int MAX_N = 50;
const int dy[] = {0, 0, -1, 1};
const int dx[] = {-1, 1, 0, 0};
int m, n, k;
int adj[MAX_N + 1][MAX_N + 1];

void flood_fill(int y, int x)
{
    adj[y][x] = 0;

    for(int k = 0; k < 4; ++k)
    {
        int ny = y + dy[k];
        int nx = x + dx[k];

        if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if(adj[ny][nx])
            flood_fill(ny, nx);
    }
}

void proc()
{
    memset(adj, 0, sizeof(adj));

    cin >> m >> n >> k;

    for(int i = 0; i < k; ++i)
    {
        int a, b;
        cin >> b >> a;
        adj[a][b] = 1;
    }

    int ans = 0;

    for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j)
    {
        if(adj[i][j])
        {
            flood_fill(i, j);
            ++ans;
        }
    }

    cout << ans << "\n";
}

int main()
{
    int tc;
    for(scanf("%d", &tc); tc--; )
        proc();
    return 0;
}
