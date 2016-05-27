#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

const int MAX_N = 200;
const int INF = 1e9;
int N, M;
int capacity[MAX_N + 1][MAX_N + 1];
int flow[MAX_N + 1][MAX_N + 1];

int max_flow(int src, int sink)
{
    memset(flow, 0, sizeof(flow));
    int ret = 0;

    while(true)
    {
        vector<int> parent(MAX_N + 1, -1);
        queue<int> q;

        // find augmenting path
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

        // if no more augmenting path
        if(parent[sink] == -1) break;

        // find a minimum residual flow
        int path_flow = INF;

        for(int p = sink; p != src; p = parent[p])
        {
            if(path_flow > capacity[parent[p]][p] - flow[parent[p]][p])
                path_flow = capacity[parent[p]][p] - flow[parent[p]][p];
        }

        // update path
        for(int p = sink; p != src; p = parent[p])
        {
            flow[p][parent[p]] -= path_flow;
            flow[parent[p]][p] += path_flow;
        }

        // add current flow
        ret += path_flow;
    }

    return ret;
}

void proc()
{
    memset(capacity, 0, sizeof(capacity));

    cin >> N >> M;

    for(int i = 0; i < M; ++i)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        capacity[a][b] = c;
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
