#include <cstdio>
int n;
int arr[101][101];
int cache[101][101];

int jump(int y, int x)
{
	if(y >= n || x >= n) return 0;
	if(y == n - 1 && x == n - 1) return 1;

	int &ret = cache[y][x];
	if(ret != -1) return ret;

	return ret = jump(y + arr[y][x], x) || jump(y, x + arr[y][x]);
}

void proc()
{
	int tc;
	scanf("%d", &tc);

	while(tc--)
	{
		scanf("%d", &n);

		for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) 
		{
			scanf("%d", &arr[i][j]);
			cache[i][j] = -1;
		}

		printf("%s\n", jump(0, 0) ? "YES" : "NO");
	}
}

int main()
{
	proc();
}
