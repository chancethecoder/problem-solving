#include <cstdio>
int n;
int arr[1010];
int cache[1010];

// Longest Increasig Subsequent //
void proc()
{
	scanf("%d", &n);

	for(int i = 0; i < n; ++i) 
	{
		scanf("%d", &arr[i]);
		cache[i] = 1;
	}

	for(int i = 1; i < n; ++i) for(int j = 0; j < i; ++j)
	{
		if(arr[i] > arr[j] && cache[i] < cache[j] + 1)
		{
			cache[i] = cache[j] + 1;
		}
	}

	printf("%d\n", cache[n-1]);
}

int main()
{
	proc();
}
