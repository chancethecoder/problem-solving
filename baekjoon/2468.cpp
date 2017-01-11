#include <iostream>
#include <cstdio>
#include <cstring>

#define MAX(a,b) (a<b?b:a)

using namespace std;

const int MAX_N = 100;
const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};
int N;
int map[MAX_N][MAX_N];
int visit[MAX_N][MAX_N];

void floodfill(int y, int x, int h) {
    visit[y][x] = 1;

    for(int k = 0; k < 4; k++) {
        int ny = y + dy[k];
        int nx = x + dx[k];

        if(nx < 0 | nx > N - 1 | ny < 0 | ny > N - 1) continue;
        if(visit[ny][nx]) continue;
        if(map[ny][nx] <= h) continue;

        floodfill(ny, nx, h);
    }
}

int solve(int h) {
    memset(visit, 0, sizeof(visit));

    int ret = 0;
    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) {
        if(map[i][j] <= h) continue;
        if(visit[i][j]) continue;
        ret++;
        floodfill(i, j, h);
    }

    return ret;
}

int main() {
    cin >> N;

    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) {
        cin >> map[i][j];
    }

    int ans = 0;
    for(int h = 0; h <= MAX_N; h++) {
        int cur = solve(h);
        ans = MAX(ans, cur);
    }

    cout << ans << endl;
}
