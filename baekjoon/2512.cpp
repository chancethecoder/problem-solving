#include <cstdio>
#define max(a,b) ((a)<(b)?(b):(a))
#define min(a,b) ((a)<(b)?(a):(b))
const int MAX_N = 10000;
int n, m;
int arr[MAX_N];

int solve()
{
	int low = 0, high = 0;

	for(int i = 0; i < n; ++i)
		if(arr[i] > high) high = arr[i];

	int ret = 0;

	while(low <= high)
	{
		int mid = (low + high) / 2;

		int sum = 0;
		for(int i = 0; i < n; ++i)
			sum += min(arr[i], mid);

		if(sum <= m)
		{
			ret = max(ret, mid);
			low = mid + 1;
		}
		else
			high = mid - 1;
	}

	return ret;
}

void proc()
{
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) scanf("%d", &arr[i]);
	scanf("%d", &m);
	printf("%d\n", solve());
}

int main()
{
	proc();
	return 0;
}
