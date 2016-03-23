#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int MAX_V = 20010;
const int INF = 987654321;

void dijkstra(vector<pair<int, int> > *adj, int src, int v)
{
	vector<int> dist(v+1, INF);
	dist[src] = 0;

	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, src));

	while(!pq.empty())
	{
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if(dist[here] < cost) continue;

		for(int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i].first;
			int next_dist = adj[here][i].second + cost;

			if(dist[there] > next_dist)
			{
				dist[there] = next_dist;
				pq.push(make_pair(-next_dist, there));
			}
		}
	}

	for(int i = 1; i <= v; i++)
	{
		if(dist[i] >= INF) puts("INF");
		else printf("%d\n", dist[i]);
	}
}

void proc()
{
	int v, e, src;
	vector<pair<int, int> > adj[MAX_V];
	scanf("%d %d %d", &v, &e, &src);

	for(int i = 0; i < e; i++)
	{
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		for(int j = 0; j < adj[u].size(); j++)
			if(adj[u][j].first == v && adj[u][j].second < w) continue;
		adj[u].push_back(make_pair(v, w));
	}

	dijkstra(adj, src, v);
}

int main()
{
	proc();
}
