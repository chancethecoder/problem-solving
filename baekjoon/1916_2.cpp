#include <cstdio>
#include <vector>
using namespace std;
const int INF = 987654321;
vector<pair<int, int> > adj[1001];
int n, m, s, e;

int dijkstra()
{
	vector<int> dist(n+1, INF);
	vector<bool> visited(n+1, false);

	dist[s] = 0;

	while(true)
	{
		int closest = INF;
		int here;

		for(int i = 1; i <= n; i++)
		{
			if(closest > dist[i] && !visited[i])
			{
				closest = dist[i];
				here = i;
			}
		}
		if(closest == INF) break;
		if(here == e) break;
		visited[here] = true;

		for(int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i].first;
			int next_cost = adj[here][i].second + closest;

			if(next_cost < dist[there]) dist[there] = next_cost;
		}
	}
	return dist[e];
}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		adj[a].push_back(make_pair(b, c));
	}
	scanf("%d %d", &s, &e);
	printf("%d\n", dijkstra());
}
