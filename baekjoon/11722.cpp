#include <cstdio>
#define max(a,b) ((a)<(b)?(b):(a))
const int MAX_N = 1000;
int n;
int arr[MAX_N];
int cache[MAX_N];

int solve()
{
	for(int i = 0; i < n; ++i) cache[i] = 1;

	for(int i = 1; i < n; ++i)
	{
		for(int j = 0; j < i; ++j)
		{
			if(arr[i] < arr[j] && cache[i] < cache[j] + 1)
				cache[i] = cache[j] + 1;
		}
	}

	int ret = 0;

	for(int i = 0; i < n; ++i)
		ret = max(ret, cache[i]);

	return ret;
}

void proc()
{
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) scanf("%d", &arr[i]);
	printf("%d\n", solve());
}

int main()
{
	proc();
	return 0;
}
