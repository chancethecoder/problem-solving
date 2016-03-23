#include <cstdio>
#include <cstring>
#define MOD 10007
int n;
int dp[1010][10];

void proc()
{
	scanf("%d", &n);

	for(int i = 0; i <= 9; i++) dp[0][i] = 1;

	for(int i = 1; i <= n; i++)
	{
		dp[i][0] = dp[i-1][0];

		for(int j = 1; j <= 9; j++) for(int k = 0; k <= j; k++)
		{
			dp[i][j] = (dp[i][j] + dp[i-1][k]) % MOD;
		}
	}

	printf("%d\n", dp[n][9]);
}

int main()
{
	proc();
}
