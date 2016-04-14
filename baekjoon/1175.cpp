/*
5 10
C.........
..........
.....S....
..........
.........C
25
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;
const int MAX_N = 50;
const int INF = 1e9;
const int dy[] = {0, 0, -1, 1};
const int dx[] = {-1, 1, 0, 0};
int N, M;
char map[MAX_N][MAX_N];
int cache[MAX_N][MAX_N][4][2][2];
pair<int, int> S;
vector<pair<int, int> > C;

int solve(int y, int x, int dir, bool picked1, bool picked2)
{
    if(y == S.first && x == S.second && picked1 && picked2) return 0;

    int &ret = cache[y][x][dir][picked1][picked2];
    if(ret != -1) return ret;

    ret = INF;

    for(int k = 0; k < 4; ++k)
    {
        int ny = y + dy[k];
        int nx = x + dx[k];

        if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
        if(k == dir || map[ny][nx] == '#') continue;

        int tmp = solve(ny, nx, k,
                    picked1 || (ny == C[0].first && nx == C[0].second),
                    picked2 || (ny == C[1].first && nx == C[1].second)) + 1;
        if(ret > tmp) ret = tmp;
    }

    return ret;
}

void proc()
{
    cin >> N >> M;

    for(int i = 0; i < N; ++i)
    {
        getchar(); scanf("%s", map[i]);

        for(int j = 0; j < M; ++j)
            if(map[i][j] == 'S')
                S.first = i, S.second = j;
            else if(map[i][j] == 'C')
                C.push_back(make_pair(i, j));
    }

    
}

int main()
{
    proc();
    return 0;
}
