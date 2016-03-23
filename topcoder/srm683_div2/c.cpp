#include <vector>
using namespace std;

struct SubtreesCounting{
	const int MOD = 1000000007;
	int a[100010];
	vector<int> tree[100010];

	int count(int u)
	{
		if(tree[u].empty()) return 1;

		int ret = 0;
		for(int i = 0; i < tree[u].size(); i++)
		{
			ret += count(tree[u][i]);
		}

		return ret + 1;
	}

	int sumOfSizes(int n, int a0, int b, int c, int m)
	{
		a[0] = a0;

		for(int i = 1; i <= n-2; i++)
			a[i] = ((((long long)b * a[i-1]) % m) + c) % m;

		for(int i = 1; i <= n-1; i++)
		{
			int j = a[i-1] % i;
			tree[i].push_back(j);
		}

		int ans = 0;

		for(int i = 1; i < n; i++)
		{
			ans = (ans + count(i)) % MOD;
		}

		return ans;
	}

};
