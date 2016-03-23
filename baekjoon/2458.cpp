#include <cstdio>
int n, m;
int adj[501][501];

void floyd()
{
	for(int k = 1; k <= n; ++k)
	{
		for(int i = 1; i <= n; ++i)
		{
			if(adj[i][k] == 0) continue;
			for(int j = 1; j <= n; ++j)
			{
				if(adj[k][j] == 0 || i == j) continue;

				if(adj[i][k] * adj[k][j] == 1)
					adj[i][j] = adj[i][k];
			}
		}
	}
}

void proc()
{
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; ++i)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a][b] = 1;
		adj[b][a] = -1;
	}

	floyd();

	int ans = 0;

	for(int i = 1; i <= n; ++i)
	{
		bool flag = true;
		for(int j = 1; j <= n; ++j)
			if(i != j && adj[i][j] == 0) flag = false;

		if(flag) ++ans;
	}
	
	printf("%d\n", ans);
}

int main()
{
	proc();
	return 0;
}
