#include <cstdio>
#include <vector>
using namespace std;
int n, m;
int adj[101][101];
vector<int> route[101][101];

void init()
{
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if(adj[a][b] == 0 || adj[a][b] > c) 
		{
			adj[a][b] = c;
			if(!route[a][b].empty()) continue;
			route[a][b].push_back(a);
			route[a][b].push_back(b);
		}
	}
}

void solve()
{
	for(int k = 1; k <= n; k++) for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++)
	{
		if(i == j) continue;
		if(adj[i][k] == 0 || adj[k][j] == 0) continue;

		if(adj[i][j] == 0 || adj[i][j] > adj[i][k] + adj[k][j]) 
		{
			adj[i][j] = adj[i][k] + adj[k][j];
			route[i][j] = route[i][k];
			route[i][j].pop_back();
			for(int it : route[k][j]) route[i][j].push_back(it);
		}
	}
}

void ans()
{
	for(int i = 1; i <= n; i++) 
	{
		for(int j = 1; j <= n; j++) printf("%d ", adj[i][j]);
		putchar(10);
	}
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++)
	{
		printf("%d ", route[i][j].size());
		for(int it : route[i][j]) printf("%d ", it);
		putchar(10);
	}
}

int main()
{
	init();
	solve();
	ans();
}
