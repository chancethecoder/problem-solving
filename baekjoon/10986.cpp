#include <cstdio>
int n, m, sol;
int sum[1000010];

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1, a; i <= n; i++)
	{
		scanf("%d", &a);
		sum[i] = sum[i-1] + a;
	}
}
