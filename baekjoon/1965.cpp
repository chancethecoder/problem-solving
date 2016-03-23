#include <cstdio>
int n;
int arr[1001];
int cache[1001];

int lis()
{
	int ret = 0;

	for(int i = 0; i < n; ++i) cache[i] = 1;

	for(int i = 1; i < n; ++i) for(int j = 0; j < i; ++j)
	{
		if(arr[i] > arr[j] && cache[i] < cache[j] + 1)
			cache[i] = cache[j] + 1;

		if(ret < cache[i]) 
			ret = cache[i];
	}

	return ret;
}

void proc()
{
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) scanf("%d", &arr[i]);
	printf("%d\n", lis());
}

int main()
{
	proc();
	return 0;
}
