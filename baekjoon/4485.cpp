#include <cstdio>
#include <limits>
#include <queue>
using namespace std;
const int INF = numeric_limits<int>::max();
const int MAX_N = 125;
int n;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int adj[MAX_N][MAX_N];
int dist[MAX_N][MAX_N];

int dijkstra()
{
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			dist[i][j] = INF;

	dist[0][0] = adj[0][0];
	priority_queue<pair<int, pair<int, int> > > pq;
	pq.push(make_pair(-dist[0][0], make_pair(0, 0)));

	while(!pq.empty())
	{
		int cost = -pq.top().first;
		int x = pq.top().second.second;
		int y = pq.top().second.first;
		pq.pop();

		if(dist[y][x] < cost) continue;

		for(int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(0 > nx || nx >= n || 0 > ny || ny >= n) continue;

			int next_cost = adj[ny][nx] + cost;

			if(dist[ny][nx] > next_cost)
			{
				dist[ny][nx] = next_cost;
				pq.push(make_pair(-next_cost, make_pair(ny, nx)));
			}
		}
	}

	return dist[n-1][n-1];
}

void proc()
{
	for(int num = 1; scanf("%d", &n) && n; ++num)
	{
		for(int i = 0; i < n; ++i) 
			for(int j = 0; j < n; ++j)
				scanf("%d", &adj[i][j]);

		printf("Problem %d: %d\n", num, dijkstra());
	}
}

int main()
{
	proc();
	return 0;
}
