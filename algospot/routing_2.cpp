#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <limits>
using namespace std;
const int MAX_V = 10000;
const double INF = numeric_limits<double>::max();
vector<pair<int, double> > adj[MAX_V];
int n, m;

double dijkstra()
{
	vector<double> noise(n, INF);
	noise[0] = 0.0;

	priority_queue<pair<double, int> , vector<pair<double, int> >, greater<pair<int, int> > > pq;
	pq.push(make_pair(0.0, 0));

	while(!pq.empty())
	{
		double cur_noise = pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if(noise[here] < cur_noise) continue;

		for(int i = 0; i < adj[here].size(); ++i)
		{
			double next_noise = log(adj[here][i].second) + cur_noise;
			int there = adj[here][i].first;
			if(noise[there] > next_noise)
			{
				noise[there] = next_noise;
				pq.push(make_pair(next_noise, there));
			}
		}
	}

	return exp(noise[n-1]);
}

void proc()
{
	int tc;
	for(scanf("%d", &tc); tc--; )
	{
		scanf("%d %d", &n, &m);
		for(int i = 0; i < n; ++i)
			adj[i].clear();

		for(int i = 0; i < m; ++i)
		{
			int a, b;
			double c;
			scanf("%d %d %lf", &a, &b, &c);
			adj[a].push_back(make_pair(b, c));
			adj[b].push_back(make_pair(a, c));
		}

		printf("%.10lf\n", dijkstra());
	}
}

int main()
{
	proc();
}
