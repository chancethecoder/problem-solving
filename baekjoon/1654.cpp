#include <cstdio>
#include <algorithm>
const int MAX_K = 10000;
int k, n;
long long a[MAX_K];

long long solve()
{
	long long l = 0, r = a[k - 1];
	long long ret = 0;

	while(l <= r)
	{
		long long mid = (l + r) / 2, cnt = 0;
		printf("%lld\n", mid);
		for(int i = 0; i < k; ++i) cnt += a[i] / mid;
		if(cnt >= n)
		{
			l = mid + 1;
			if(ret < mid) ret = mid;
		}
		else r = mid - 1;
	}
	return ret;
}

void proc()
{
	scanf("%d %d", &k, &n);
	for(int i = 0; i < k; ++i) scanf("%lld", &a[i]);
	std::sort(a, a + k);
	printf("%lld\n", solve());
}

int main()
{
	proc();
	return 0;
}
