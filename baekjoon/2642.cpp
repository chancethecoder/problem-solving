#include <cstdio>
#include <vector>
using namespace std;
const int MAX_N = 6;
int map[MAX_N][MAX_N];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<pair<int, int> > adj[MAX_N][MAX_N];

int check()
{
	for(int i = 0; i < MAX_N; ++i) for(int j = 0; j < MAX_N; ++j)
	{
		if(map[i][j] == 0) continue;

		bool disconnected = true;

		for(int k = 0; k < 4; ++k)
		{
			int ny = i + dy[k];
			int nx = j + dx[k];

			if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if(map[ny][nx] == 0) continue;

			adj[i][j].push_back(make_pair(ny, nx));
			disconnected = false;
		}

		if(disconnected) return 0;
	}

	for(int i = 0; i < MAX_N; ++i) for(int j = 0; j < MAX_N; ++j)
	{
	}
}

void proc()
{
	for(int i = 0; i < MAX_N; ++i) 
		for(int j = 0; j < MAX_N; ++j)
			scanf("%d", &map[i][j]);

	printf("%d\n", check());
}

int main()
{
	proc();
	return 0;
}
