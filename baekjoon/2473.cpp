#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <limits>
using namespace std;
int n;
long long arr[5010];
long long ans[3];

void solve()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%lld", &arr[i]);
	sort(arr, arr + n);

	long long min_sum = numeric_limits<long long>::max();

	for(int i = 0; i < n; i++)
	{
		int l = 0;
		int r = n-1;
		while(l < r)
		{
			long long sum = arr[l] + arr[r];

			if(l != i && r != i && min_sum > abs(sum + arr[i]))
			{
				min_sum = abs(sum + arr[i]);
				ans[0] = arr[l];
				ans[1] = arr[i];
				ans[2] = arr[r];
			}
            if(min_sum == 0) return;
			if(sum + arr[i] < 0) l++;
			else r--;
		}
	}
}

int main()
{
	solve();
	sort(ans, ans+3);
	printf("%lld %lld %lld\n", ans[0], ans[1], ans[2]);
}
