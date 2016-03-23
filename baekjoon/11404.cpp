#include <cstdio>
#define min(a,b) ((a)<(b)?(a):(b))
int n, m;
int adj[101][101];

void init()
{
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if(adj[a][b] == 0) adj[a][b] = c;
		else adj[a][b] = min(adj[a][b], c);
	}
}

void solve()
{
	for(int k = 1; k <= n; k++) for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++)
	{
		if(i == j) continue;
		if(adj[i][k] == 0 || adj[k][j] == 0) continue;

		if(adj[i][j] == 0) adj[i][j] = adj[i][k] + adj[k][j];
		else adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
	}
}

void ans()
{
	for(int i = 1; i <= n; i++) 
	{
		for(int j = 1; j <= n; j++) printf("%d ", adj[i][j]);
		putchar(10);
	}
}

int main()
{
	init();
	solve();
	ans();
}
