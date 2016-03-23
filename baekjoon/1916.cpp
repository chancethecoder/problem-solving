#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int INF = 987654321;
vector<pair<int, int> > adj[1001];
int n, m, s, e;

int dijkstra()
{
	vector<int> dist(n+1, INF);
	dist[s] = 0;

	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, s));

	while(!pq.empty())
	{
		int here = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		if(here == e) break;
		if(cost > dist[here]) continue;

		for(int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i].first;
			int next_cost = adj[here][i].second + cost;

			if(next_cost < dist[there])
			{
				dist[there] = next_cost;
				pq.push(make_pair(-next_cost, there));
			}
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
