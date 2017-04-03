#include <iostream>
#define max(a,b) (a<b?b:a)

using namespace std;

int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };
int R, C;
char map[22][22];
bool visit[30];

int solve(int y, int x)
{
    int ret = 0;
    visit[map[y][x] - 'A'] = true;
    for (int k = 0; k < 4; k++)
    {
        int ny = y + dy[k];
        int nx = x + dx[k];
        if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
        if (visit[map[ny][nx] - 'A']) continue;
        int tmp = solve(ny, nx) + 1;
        ret = max(ret, tmp);
    }
    visit[map[y][x] - 'A'] = false;
    return ret;
}

int main() {

    cin >> R >> C;
    for (int i = 0; i < R; i++)
        cin >> map[i];
    cout << solve(0, 0) + 1 << endl;

    return 0;
}
