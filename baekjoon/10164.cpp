#include <cstdio>
long long dp[16][16];

int proc()
{
	for(int i = 0; i < 16; i++) 
		dp[0][i] = dp[i][0] = 1;
	for(int i = 1; i < 16; i++) for(int j = 1; j < 16; j++)
		dp[i][j] = dp[i][j-1] + dp[i-1][j];
}

int main()
{
	proc();
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);

	long long sol;
	if(k == 0) sol = dp[n - 1][m - 1];
	else
	{
		--k;
		int _n = k / m;
		int _m = k % m;
		sol = dp[_n][_m] * dp[n - 1 - _n][m - 1 - _m];
	}
	printf("%lld\n", sol);
}
