#include <cstdio>

int main()
{
	int n, sol = 0;
	scanf("%d", &n);

	for(int x = 1, i = 1; i <= n; ++i)
	{
		x *= i;
		while(x % 10 == 0)
		{
			sol++;
			x /= 10;
		}
		x %= 10;
	}
	printf("%d\n", sol);
}
