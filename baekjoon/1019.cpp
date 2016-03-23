#include <cstdio>
int n;
int cnt[10];

int main()
{
	scanf("%d", &n);
	for(int i = 1, j; i <= n; ++i)
	{
		j = i;
		while(j)
		{
			cnt[j%10]++;
			j /= 10;
		}
	}

	for(int i = 0; i < 10; i++) printf("%d ", cnt[i]);
	putchar(10);
}
