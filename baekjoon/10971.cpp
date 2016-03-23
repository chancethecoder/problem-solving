#include <iostream>
#include <cstdio>

using namespace std;
const int MAX_N = 10;
const int INF = 1e9;
int N;
int adj[MAX_N][MAX_N];
bool visit[MAX_N];

int solve(int from, int cnt)
{
    if(cnt == N) return 0;

    int ret = INF;

    for(int to = 0; to < N; ++to)
    {
        if(!adj[from][to] || visit[to]) continue;

        visit[to] = true;

        int tmp = adj[from][to] + solve(to, cnt + 1);
        if(ret > tmp) ret = tmp;

        visit[to] = false;
    }

    return ret;
}

void proc()
{
    cin >> N;

    for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j)
    {
        cin >> adj[i][j];
    }

    cout << solve(0, 0) << "\n";
}

int main()
{
    proc();
    return 0;
}
