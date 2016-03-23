/*

n, m 받는다.
m열짜리 n행 받는다.
테이블 돌면서 S, C1, C2 좌표를 찾는다.

5 10
C.........
..........
.....S....
..........
.........C
26
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#define min(a,b) ((a)<(b)?(a):(b))

using namespace std;
const int MAX_N = 50;
const int INF = 1000000007;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int N, M;
int cache[MAX_N + 1][MAX_N + 1][4][2];
char map[MAX_N + 1][MAX_N + 1];
pair<int, int> S, C[2];

void proc()
{
    int idx;
    memset(cache, -1, sizeof(cache));
    cin >> n >> m;

    for(int i = 0; i < n; ++i)
    {
        cin >> map[i];
        for(int j = 0; j < m; ++j)
        {
            if(map[i][j] == 'S') S = make_pair(i, j);
            else if(map[i][j] == 'C') C[idx++] = make_pair(i, j);
        }
    }
}

int main()
{
    proc();
    return 0;
}
