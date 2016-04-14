#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

typedef long long ll;
using namespace std;
const int MAX_N = 800;
const int MAX_E = 200000;
const int INF = 1000000007;
int N, E;
vector<pair<int, int> > adj[MAX_N + 1];

ll dijkstra(int src, int dest)
{
    vector<int> dist(MAX_N + 1, INF);
    priority_queue<pair<int, int> > pq;

    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty())
    {
        int here = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        if(dist[here] < cost) continue;
        if(here == dest) break;

        for(int i = 0; i < adj[here].size(); ++i)
        {
            int there = adj[here][i].first;
            int next_cost = cost + adj[here][i].second;

            if(next_cost < dist[there])
            {
                dist[there] = next_cost;
                pq.push({-next_cost, there});
            }
        }
    }

    return dist[dest];
}

void proc()
{
    cin >> N >> E;

    for(int i = 0; i < E; ++i)
    {
        int a, b, c;

        scanf("%d %d %d", &a, &b, &c);

        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    int v1, v2;

    cin >> v1 >> v2;

    ll way1 = dijkstra(1, v1) + dijkstra(v1, v2) + dijkstra(v2, N);
    ll way2 = dijkstra(1, v2) + dijkstra(v2, v1) + dijkstra(v1, N);

    ll ans = way1 < way2 ? way1 : way2;

    if(INF <= ans) puts("-1");
    else printf("%lld\n", ans);
}

int main()
{
    proc();
    return 0;
}
