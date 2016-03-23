#include <iostream>
#include <cstdio>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n, m;
int sum;
bool flag;
pair<int, char> a[200001];
pair<int, char> b[200001];

int solve()
{
	int ret = 0;

	if(m == 1)
	{
		for(int i = 0; i < n; ++i)
			if(a[i].second == b[0].second) 
				ret += (a[i].first - b[0].first);
	}
	else if(m == 2)
	{
		for(int i = 0; i < n - 1; ++i)
			if(a[i].second == b[0].second && a[i+1].second == b[1].second)
				ret += (flag ? 
						(a[i].first + a[i+1].first) - (b[0].first + b[1].first) : 
						min(a[i].first-b[0].first, a[i+1].first-b[1].first));
	}
	else
	{
		for(int i = 0; i < n-1; ++i)
		{
			int j = 1;
			while(j < m - 1 && b[j] == a[i+j]) ++j;

			if(j == m - 1)
			{
				if(flag)
				{
					int t_sum = 0;
					for(int k = i; k <= i + j; ++k)
						t_sum += a[k].first;

					ret += t_sum - sum;
				}
				else
					ret += min(a[i].first - b[0].first, a[i+j].first - b[j].first);
			}
		}
	}

	return ret;
}

void proc()
{
	cin >> n >> m;

	for(int i = 0; i < n; ++i)
		scanf("%d-%c", &a[i].first, &a[i].second);

	for(int i = 0; i < m; ++i)
	{
		scanf("%d-%c", &b[i].first, &b[i].second);
		sum += b[i].first;
	}
	
	flag = true;
	for(int i = 0; i < m - 1; ++i)
		if(b[i].second != b[i].second) flag = false;

	printf("%d\n", solve());
}

int main()
{
	proc();
	return 0;
}
