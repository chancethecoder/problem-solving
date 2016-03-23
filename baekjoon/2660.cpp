#include <cstdio>
#include <vector>
#define max(a,b) ((a)<(b)?(b):(a))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
const int INF = 987654321;
int n, min_score;
int adj[51][51];
int score[51];
vector<int> candidates;

void floyd()
{
	for(int k = 1; k <= n; k++) 
	{
		for(int i = 1; i <= n; i++)
		{
			if(adj[i][k] == 0) continue;
			for(int j = 1; j <= n; j++)
			{
				if(i == j || adj[k][j] == 0) continue;
				adj[i][j] = min((!adj[i][j] ? INF : adj[i][j]), adj[i][k] + adj[k][j]);
			}
		}
	}
}

void proc()
{
	scanf("%d", &n);
	for(int a, b; true;)
	{
		scanf("%d %d", &a, &b);
		if(a == -1) break;
		adj[a][b] = adj[b][a] = 1;
	}
	floyd();
	min_score = 1 << 30;

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
			if(score[i] < adj[i][j]) score[i] = adj[i][j];

		if(score[i] == min_score) candidates.push_back(i);
		else if(score[i] < min_score)
		{
			min_score = score[i];
			candidates.clear();
			candidates.push_back(i);
		}
	}

	printf("%d %d\n", min_score, candidates.size());
	for(int it : candidates) printf("%d ", it);
}

int main()
{
	proc();
}
