#include <cstdio>
#define max(a,b) ((a)<(b)?(b):(a))
int n, m;
int maze[1010][1010];

int main()
{
	scanf("%d%d", &n, &m);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) scanf("%d", &maze[i][j]);

	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
	{
		if(i == 0) maze[i][j] += maze[i][j-1];
		else if(j == 0) maze[i][j] += maze[i-1][j];
		else 
			maze[i][j] += max(maze[i-1][j], maze[i][j-1]);
	}

	printf("%d\n", maze[n-1][m-1]);
}
