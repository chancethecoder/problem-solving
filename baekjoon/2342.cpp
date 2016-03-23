#include <cstdio>
#include <cstdlib>
#include <cstring>
#define min(a,b) ((a)<(b)?(a):(b))
#define INF 1000000
using namespace std;
int n;
int move[100010];
int dp[5][5][100010];

int work(int from, int to)
{
	if(to == 0) return INF;
	if(from == 0) return 2;

	int diff = abs(to - from);

	if(diff == 0) return 1;
	else if(diff == 2) return 4;
	else return 3;
}

void proc()
{
	for(; scanf("%d", &move[++n]) && move[n]; );

	for(int i = 0; i < 5; ++i) 
		for(int j = 0; j <5; ++j) 
			memset(dp[i][j], INF, sizeof(dp[i][j]));

	dp[move[1]][0][1] = dp[0][move[1]][1] = 2;


	for(int i = 2; i <= n; ++i)
	{
		for(int j = 0; j <= 4; ++j)
		{
			/*
			for(int k = 0; k <= 4; ++k)
			{
				dp[j][move[i]][i] = min(dp[j][move[i]][i], dp[j][k][i-1] + work(k, move[i]));
				dp[move[i]][j][i] = min(dp[move[i]][j][i], dp[k][j][i-1] + work(k, move[i]));
			}
			*/
			
			dp[j][move[i]][i] = min(dp[j][move[i-1]][i-1] + work(move[i-1], move[i]), dp[move[i-1]][move[i]][i-1] + work(move[i-1], j));
			dp[move[i]][j][i] = min(dp[move[i-1]][j][i-1] + work(move[i-1], move[i]), dp[move[i-1]][move[i]][i-1] + work(move[i-1], j));
			
		}

		if(i == n)
		{
			int ans = INF;

			for(int j = 0; j <= 4; ++j)
			{
				ans = min(ans, dp[move[n]][j][n]);
				ans = min(ans, dp[j][move[n]][n]);
			}

			printf("%d\n", ans);
		}
	}
}

int main()
{
	proc();
}
