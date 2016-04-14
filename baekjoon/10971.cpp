#include <iostream>
#include <cstdio>

using namespace std;
const int MAX_N = 10;
const int INF = 1e9 + 7;
int N;
int ans = INF;
int adj[MAX_N][MAX_N];
int visit[MAX_N];

void solve(int from, int cost, int cnt)
{
    if(cnt == N)
    {
        if(ans > cost + adj[from][0]) ans = cost + adj[from][0];
        return;
    }

    for(int to = 0; to < N; ++to)
    {
        if(!adj[from][to] || visit[to]) continue;
        visit[to] = true;
        solve(to, cost + adj[from][to], cnt + 1);
        visit[to] = false;
    }
}

void proc()
{
    cin >> N;

    for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j) cin >> adj[i][j];

    visit[0] = true;
    solve(0, 0, 1);

    cout << ans << "\n";
}

int main()
{
    proc();
    return 0;
}
