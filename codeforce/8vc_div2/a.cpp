#include <cstdio>
#define max(a,b) ((a)<(b)?(b):(a))
#define min(a,b) ((a)<(b)?(a):(b))
int r, c, n, k;
int a[11][11];

int main()
{
	scanf("%d %d %d %d", &r, &c, &n, &k);
	for(int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d %d", &y, &x);
		a[y][x] = 1;
	}

	int ans = 0;
	for(int i = 1; i <= r; i++) for(int j = 1; j <= c; j++)
	{
		for(int y = i; y <= r; y++) for(int x = j; x <= c; x++)
		{
			int cnt = 0;
			for(int ti = i; ti <= y; ti++) for(int tj = j; tj <= x; tj++)
			{
				if(a[ti][tj]) cnt++;
			}
			if(cnt >= k) ans++;
		}
	}

	printf("%d\n", ans);
}
