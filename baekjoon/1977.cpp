#include <cstdio>
int m, n;
int min, sum;

void proc()
{
	scanf("%d %d", &m, &n);

	while(min * min < m) ++min;

	if(min * min > n)
	{
		puts("-1");
	}
	else
	{
		sum = min * min;

		for(int i = min + 1; i*i <= n; ++i) sum += i * i;
		
		printf("%d\n%d\n", sum, min * min);
	}
}

int main()
{
	proc();
	return 0;
}
