#include <cstdio>
#include <vector>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
const int MAX_N = 100000;
const int INF = 1000000007;
int n;
int cache[MAX_N+1];
vector<int> v;

void init()
{
	for(int i = 1; i <= n; ++i) cache[i] = INF;
	for(int i = 1; i*i <= n; ++i) 
	{
		cache[i*i] = 1;
		v.push_back(i*i);
	}
}

int solve()
{
	for(int i = 0; i < v.size(); ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			if(j - v[i] > 0)
				cache[j] = min(cache[j], cache[j-v[i]] + cache[v[i]]);
		}
	}

	return cache[n];
}

void proc()
{
	scanf("%d", &n);
	init();
	printf("%d\n", solve());
}

int main()
{
	proc();
	return 0;
}
