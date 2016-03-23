#include <cstdio>
#include <string>
#include <queue>
using namespace std;
const int MAX_N = 10;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int tc, n, m;
char maze[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

void reset()
{
	for(int i = 0; i < n; ++i) 
		for(int j = 0; j < m; ++j) 
			visited[i][j] = false;
}

bool all_visited()
{
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			if(maze[i][j] == '.' && !visited[i][j]) return false;
	return true;
}

const char* solve()
{
	for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j)
	{
		if(maze[i][j] != '.') continue;

		int y = i, x = j;
		reset();

		queue<pair<pair<int, int>, string> > q;
		q.push(make_pair(make_pair(y, x), ""));
		visited[y][x] = true;

		while(!q.empty())
		{
			y = q.front().first.first;
			x = q.front().first.second;
			string order = q.front().second;
			q.pop();

			if(order.length() > 10) continue;

			for(int k = 0; k < 4; ++k)
			{
				int ty = y;
				int tx = x;
				string torder(order);

				while(maze[ty+dy[k]][tx+dx[k]] == '.' && 
						!visited[ty+dy[k]][tx+dx[k]] || 
						maze[ty + dy[k]][tx + dx[k]] == 'O')
				{
					ty += dy[k];
					tx += dx[k];
					visited[ty][tx] = true;
				}

				if(ty == y && tx == x) continue;

				torder += "LRUD"[k];

				if(maze[ty][tx] == 'O' && 
						torder.length() <= 10 && 
						all_visited())
					return torder.c_str();

				q.push(make_pair(make_pair(ty, tx), torder));
			}
		}
	}

	return "XHAE";
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

		printf("%s\n", solve());
	}
}

int main()
{
	proc();
}
