#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX_N = 1000;
int n, k, w;
int dist[MAX_N + 1];
int memo[MAX_N + 1];
vector<vector<int> > adj;

int solve(int cur) {
  int &ret = memo[cur];
  if(ret != -1) return ret;

  ret = 0;

  for(int i = 0; i < adj[cur].size(); i++) {
    ret = max(ret, solve(adj[cur][i]));
  }

  return ret += dist[cur];
}

int main() {
	int tc; cin >> tc;

  while(tc--) {
    memset(memo, -1, sizeof(memo));
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
		cout << solve(w) << endl;
	}

	return 0;
}
