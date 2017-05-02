#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX_N = 1000;
int n, k, w;
int dist[MAX_N + 1];
vector<vector<int> > adj;

int solve() {
	int ret = 0;
	int cost[n + 1] = { 0 };
	queue<int> q;
	q.push(w);
	cost[w] = dist[w];

	while(!q.empty()) {
		int cur = q.front(); q.pop();
		int cur_cost = cost[cur];

		if(adj[cur].empty())
			ret = max(ret, cur_cost);

		for(int i = 0; i < adj[cur].size(); i++) {
			int next = adj[cur][i];
			int next_cost = cur_cost + dist[next];

			if(next_cost < cost[next]) continue;
			cost[next] = next_cost;
			q.push(next);
		}
	}

	return ret;
}

int main() {
	int tc; cin >> tc;

  while(tc--) {
		cin >> n >> k;
		adj.clear();
		adj.resize(n + 1);

		for(int i = 1; i <= n; i++) {
			scanf("%d", &dist[i]);
		}

		for(int i = 0, a, b; i < k; i++) {
			scanf("%d %d", &a, &b);
			adj[b].push_back(a);
		}

		cin >> w;
		cout << solve() << endl;
	}

	return 0;
}
