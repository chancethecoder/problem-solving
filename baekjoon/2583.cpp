#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 100;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
int map[MAX_N][MAX_N];
int N, M, K;
int cnt;
int S[MAX_N];

int floodfill(int j, int i) {
    int ret = map[j][i] = 1;

    for(int k = 0; k < 4; k++) {
        int ny = j + dy[k];
        int nx = i + dx[k];

        if(nx < 0 | nx > N - 1 | ny < 0 | ny > M - 1) continue;

        if(!map[ny][nx]) {
            ret += floodfill(ny, nx);
        }
    }
    return ret;
}

int main() {
    cin >> M >> N >> K;

    for(int i = 0; i < K; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for(int j = x1; j < x2; j++) for(int k = y1; k < y2; k++)
            map[k][j] = 1;
    }

    for(int j = 0; j < M; j++) for(int i = 0; i < N; i++) {
        if(!map[j][i]) {
            S[cnt++] = floodfill(j, i);
        }
    }

    sort(S, S + cnt);

    cout << cnt << endl;
    for(int i = 0; i < cnt; i++)
        cout << S[i] << " ";
}
