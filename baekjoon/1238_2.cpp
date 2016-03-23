#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int INF = 987654321;
int n, m, x;
vector<pair<int, int> > adj[1001];
vector<pair<int, int> > adj_rev[1001];
int dist[1001], dist_rev[1001];

void init()
{
	scanf("%d %d %d", &n, &m, &x);
	for(int i = 0; i < m; i++)
	{
		int a, b, w;
		scanf("%d %d %d", &a, &b, &w);
		adj[a].push_back(make_pair(b, w));
		adj_rev[b].push_back(make_pair(a, w));
	}

	for(int i = 1; i <= n; i++)
		dist[i] = dist_rev[i] = INF;
}

void dijkstra(vector<pair<int, int> > *adj, int start, int V, int *dist)
{
	priority_queue<pair<int, int> > pq;
	dist[start] = 0;
	pq.push(make_pair(0, start));

	while(!pq.empty())
	{
		int here = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		if(dist[here] < cost) continue;

		for(int i = 0; i < adj[here].size(); ++i)
		{
			int there = adj[here][i].first;
			int next_cost = adj[here][i].second + cost;

			if(dist[there] > next_cost)
			{
				dist[there] = next_cost;
				pq.push(make_pair(-next_cost, there));
			}
		}
	}
}

int solve()
{
	dijkstra(adj, x, n, dist);
	dijkstra(adj_rev, x, n, dist_rev);
	int ans = 0;
	for(int i = 1; i <= n; i++)
		if(ans < dist[i] + dist_rev[i]) ans = dist[i] + dist_rev[i];
	return ans;
}

int main()
{
	init();
	printf("%d\n", solve());
}
