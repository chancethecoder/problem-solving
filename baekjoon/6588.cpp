#include <cstdio>
int n;
bool prime[1000010];

int main()
{
	for(int i = 2; i < 1000010; i++)
	{
		while(prime[i]) i++;

		for(int j = 2*i; j < 1000010; j+=i) prime[j] = true;
	}

	for(;scanf("%d", &n) && n;)
	{
		int l = 3, r = n;
		while(prime[r]) r--;

		while(1)
		{
			if(l > r)
			{
				printf("Goldbach's conjecture is wrong.\n");
				break;
			}
			if(l+r == n)
			{
				printf("%d = %d + %d\n", n, l, r);
				break;
			}
			if(l+r > n) while(prime[--r]);
			else while(prime[++l]);
		}
	}
}
