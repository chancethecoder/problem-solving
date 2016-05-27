#include <iostream>
#include <cstdio>
#define max(a,b) ((a)<(b)?(b):(a))

using namespace std;
const int MAX_N = 100000;
int n;
int arr[MAX_N];
int cache[MAX_N];

void proc()
{
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);

	int ans;
	ans = cache[0] = arr[0];
	for(int i = 1; i < n; ++i)
	{
		cache[i] = max(cache[i - 1] + arr[i], arr[i]);
		ans = max(ans, cache[i]);
	}

	printf("%d\n", ans);
}

int main()
{
	proc();
	return 0;
}
