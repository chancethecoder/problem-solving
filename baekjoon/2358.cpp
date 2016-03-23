#include <cstdio>
#include <algorithm>
int x[100010], y[100010];
int n, ans;

void proc()
{
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) scanf("%d %d", &x[i], &y[i]);

	std::sort(x, x + n);
	std::sort(y, y + n);

	for(int i = 0; i < n - 1; ++i)
	{
		if(x[i] == x[i + 1])
		{
			++ans;
			while(x[i] == x[i + 1]) ++i;
		}
	}

	for(int i = 0; i < n - 1; ++i)
	{
		if(y[i] == y[i + 1])
		{
			++ans;
			while(y[i] == y[i + 1]) ++i;
		}
	}

	printf("%d\n", ans);
}

int main()
{
	proc();
	return 0;
}
