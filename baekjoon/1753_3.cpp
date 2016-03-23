#include <cstdio>
#include <vector>
using namespace std;

const int INF = 987654321;
const int MAX_V = 20010;

vector<int> dijkstra(vector<pair<int, int> > *adj, int src, int V)
{
	vector<int> dist(V+1, INF);
	vector<bool> visited(V+1, false);

	dist[src] = 0;
//	visited[src] = true;

	while(true)
	{
		int cost = INF, here;
		for(int i = 1; i <= V; i++)
		{
			if(dist[i] < cost && !visited[i])
			{
				here = i;
				cost = dist[i];
			}
		}

		if(cost == INF) break;
		visited[here] = true;

		for(int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i].first;
			if(visited[there]) continue;
			int next = dist[here] + adj[here][i].second;
			if(dist[there] > next) dist[there] = next;
		}
	}

	return dist;
}


void proc()
{
	vector<pair<int, int> > adj[MAX_V];
	int V, E, src;
	scanf("%d %d %d", &V, &E, &src);
	for(int i = 0; i < E; i++)
	{
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		adj[u].push_back(make_pair(v, w));
	}

	vector<int> dist;
	dist = dijkstra(adj, src, V);

	for(int i = 1; i <= V; i++)
		dist[i] == INF ? puts("INF") : printf("%d\n", dist[i]);
}

int main()
{
	proc();
}
