#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
const int MAX_N = 1000;
int N, M;
bool adj[MAX_N + 1][MAX_N + 1];
vector<int> aMatch, bMatch;
vector<bool> visited;

bool dfs(int a)
{
    if(visited[a]) return false;
    visited[a] = true;

    for(int b = 0; b < M; ++b)
        if(adj[a][b])
            if(bMatch[b] == -1 || dfs(bMatch[b]))
            {
                aMatch[a] = b;
                bMatch[b] = a;
                return true;
            }

    return false;
}

int solve()
{
    aMatch = vector<int>(N, -1);
    bMatch = vector<int>(M, -1);

    int ret = 0;

    for(int start = 0; start < N; ++start)
    {
        visited = vector<bool>(N, false);
        if(dfs(start))
            ++ret;
    }

    return ret;
}

void proc()
{
    cin >> N >> M;

    for(int person = 1; person <= N; ++person)
    {
        int capable, job;
        for(scanf("%d", &capable); capable--; )
        {
            scanf("%d", &job);
            adj[person - 1][job - 1] = true;
        }
    }

    cout << solve() << "\n";
}

int main()
{
    proc();
    return 0;
}
