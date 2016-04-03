#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int MAX_N = 500;
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};
int n;
int ans;
int map[MAX_N][MAX_N];
int cache[MAX_N][MAX_N];

int solve(int y, int x)
{
    int &ret = cache[y][x];
    if(ret != -1) return ret;

    ret = 1;

    for(int k = 0; k < 4; ++k)
    {
        int ny = y + dy[k];
        int nx = x + dx[k];

        if(ny < 0 || nx < 0 || ny > n - 1 || nx > n - 1
        || map[y][x] >= map[ny][nx]) continue;

        if(ret < solve(ny, nx) + 1)
            ret = solve(ny, nx) + 1;
    }

    return ret;
}

void proc()
{
    memset(cache, -1, sizeof(cache));

    cin >> n;

    for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j)
    {
        scanf("%d", &map[i][j]);
    }

    for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j)
    {
        if(ans < solve(i, j))
            ans = solve(i, j);
    }

    cout << ans << "\n";
}

int main()
{
    proc();
    return 0;
}
