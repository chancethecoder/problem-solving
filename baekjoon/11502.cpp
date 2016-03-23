#include <cstdio>
bool prime[1001];

void init()
{
	for(int i = 2; i < 1001; ++i)
	{
		while(prime[i]) ++i;
		for(int j = 2*i; j < 1001; j += i) prime[j] = true;
	}
}

void check(int n)
{
	for(int a = 2; a < 1001; ++a)
	{
		while(prime[a]) ++a;

		for(int b = a; b < 1001; ++b)
		{
			while(prime[b]) ++b;

			int c = n - a - b;

			if(c < 2) continue;

			if(!prime[c])
			{
				printf("%d %d %d\n", a, b, c);
				return;
			}
		}
	}
	puts("0");
}

void proc()
{
	init();

	int tc, n;
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
