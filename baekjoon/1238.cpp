#include <cstdio>
int n, m, x;
int adj[1001][1001];

void init()
{
	scanf("%d %d %d", &n, &m, &x);
	for(int i = 0; i < m; ++i)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if(adj[a][b] == 0 || adj[a][b] > c) adj[a][b] = c;
	}
}

int solve()
{

	for(int k = 1; k <= n; ++k) for(int i = 1; i <= n; ++i)
	{
		if(adj[i][k] == 0) continue;
		for(int j = 1; j <= n; ++j)
		{
			if(i == j || adj[k][j] == 0) continue;

			if(adj[i][j] == 0 || adj[i][j] > adj[i][k] + adj[k][j])
				adj[i][j] = adj[i][k] + adj[k][j];
		}
	}

	int ans = 0;
	for(int i = 1; i <= n; i++)
		if(ans < adj[i][x] + adj[x][i]) ans = adj[i][x] + adj[x][i];

	return ans;
}

int main()
{
	init();
	printf("%d\n", solve());
}
