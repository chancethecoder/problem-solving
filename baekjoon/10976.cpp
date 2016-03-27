#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;
const int MAX_N = 200;
const int INF = 1e9;
int N, M;
int capacity[MAX_N + 1][MAX_N + 1];
int flow[MAX_N + 1][MAX_N + 1];

int max_flow(int src, int sink)
{
    int ret = 0;

    while(true)
    {
        vector<int> parent(MAX_N + 1, -1);
        queue<int> q;
        parent[src] = src;
        q.push(src);

        while(!q.empty() && parent[sink] == -1)
        {
            int here = q.front(); q.pop();

            for(int there = 1; there <= N; ++there)
            {
                if(capacity[here][there] - flow[here][there] > 0 && parent[there] == -1)
                {
                    q.push(there);
                    parent[there] = here;
                }
            }
        }

        if(parent[sink] == -1) break;

        for(int p = sink; p != src; p = parent[p])
        {
            ++flow[parent[p]][p];
            --flow[p][parent[p]];
        }
        ++ret;
    }

    return ret;
}

void proc()
{
    memset(capacity, 0, sizeof(capacity));
    memset(flow, 0, sizeof(flow));

    cin >> N >> M;

    for(int i = 0; i < M; ++i)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        if(a == 1 || b == N)
            capacity[a][b] = 1;
        else
            capacity[a][b] = INF;
    }

    cout << max_flow(1, N) << "\n";
}

int main()
{
    int tc;
    for(scanf("%d", &tc); tc--; )
        proc();
    return 0;
}
