#include <cstdio>
int n, ans;
int arr[1010];
int cache[1010];

// Maximum Sum Increasig Subsequent //
void proc()
{
	scanf("%d", &n);

	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
		cache[i] = arr[i];
	}

	for(int i = 1; i < n; ++i) for(int j = 0; j < i; ++j)
	{
		if(arr[i] > arr[j] && cache[i] < cache[j] + arr[i])
		{
			cache[i] = cache[j] + arr[i];
		}
	}

	for(int i = 0; i < n; ++i)
		if(ans < cache[i]) ans = cache[i];

	printf("%d\n", ans);
}

int main()
{
	proc();
}
