#include <cstdio>
bool prime[10001];
int tc, n;

void init()
{
	for(int i = 2; i < 10001; ++i)
	{
		while(prime[i]) ++i;
		for(int j = 2*i; j < 10001; j += i) prime[j] = true;
	}
}

void check(int n)
{
	for(int i = n / 2; i > 1; --i)
	{
		int a = i;
		int b = n - a;
		while(prime[a] && prime[b])
		{
			--a, ++b;
		}

		if(a < 2 || b > 10000) continue;

		if(!prime[a] && !prime[b])
		{
			printf("%d %d\n", a, b);
			return;
		}
	}
}

void proc()
{
	init();
	scanf("%d", &tc);
	while(tc--)
	{
		scanf("%d", &n);
		check(n);
	}
}

int main()
{
	proc();
	return 0;
}
