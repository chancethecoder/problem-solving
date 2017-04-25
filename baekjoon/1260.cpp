#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX_N = 1000;
int n;
int m;
int v;
vector<int> adj[MAX_N + 1];
bool visited[MAX_N + 1];

void dfs(int x) {
		visited[x] = true;
		printf("%d ", x);
		for(int i = 0; i < adj[x].size(); i++) {
				if(visited[adj[x][i]]) continue;
				dfs(adj[x][i]);
		}
}

void bfs() {
		printf("\n");
		memset(visited, false, sizeof(visited));
		queue<int> q;
		q.push(v);
		visited[v] = true;
		while(!q.empty()) {
				int x = q.front(); q.pop();
				printf("%d ", x);
				for(int i = 0; i < adj[x].size(); i++) {
						if(visited[adj[x][i]]) continue;
						q.push(adj[x][i]);
						visited[adj[x][i]] = true;
				}
		}
}

int main() {

		cin >> n >> m >> v;
		for(int i = 0, a, b; i < m; i++) {
				scanf("%d %d", &a, &b);
				if(find(adj[a].begin(), adj[a].end(), b) == adj[a].end()) {
						adj[a].push_back(b);
						adj[b].push_back(a);
				}
		}

		for(int i = 1; i <= n; i++)
				sort(adj[i].begin(), adj[i].end());

		dfs(v);
		bfs();
		return 0;
}
