#include <cstdio>
#include <cstring>
long long dp[65][10];

void proc()
{
	for(int i = 0; i <= 9; i++) dp[0][i] = 1;
	for(int i = 1; i <= 65; i++)
	{
		dp[i][0] = dp[i-1][0];
		for(int j = 1; j <= 9; j++) for(int k = 0; k <= j; k++)
		{
			dp[i][j] += dp[i-1][k];
		}
	}
}

int main()
{
	proc();
	int tc;
	for(scanf("%d", &tc); tc--;)
	{
		int n;
		scanf("%d", &n);
		printf("%lld\n", dp[n][9]);
	}
}
