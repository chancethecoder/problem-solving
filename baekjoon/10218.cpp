#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>

using namespace std;

const int MAX_N = 10;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int tc, n, m;
char maze[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

string solve()
{
}

void proc()
{
	for(scanf("%d", &tc); tc--; )
	{
		scanf("%d %d", &n, &m);

		for(int i = 0; i < n; ++i)
		{
			getchar();
			scanf("%s", maze[i]);
		}

		cout << solve() << "\n";
	}
}

int main()
{
	proc();
	return 0;
}
