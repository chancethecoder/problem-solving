#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
const int MAX_I = 300;
const int INF = 1e9 + 7;
const int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
const int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int I;
int x1, y1, x2, y2;
int dist[MAX_I][MAX_I];

int solve()
{
	memset(dist, INF, sizeof(dist));

	queue<pair<int, int> > q;

	dist[y1][x1] = 0;
	q.push({y1, x1});

	while(!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for(int k = 0; k < 8; ++k)
		{
			int ny = y + dy[k];
			int nx = x + dx[k];

			if(ny < 0 || nx < 0 || ny >= I || nx >= I) continue;

			if(dist[ny][nx] > dist[y][x] + 1)
			{
				dist[ny][nx] = dist[y][x] + 1;
				q.push({ny, nx});
			}
		}
	}

	return dist[y2][x2];
}

void proc()
{
	cin >> I;
	cin >> x1 >> y1;
	cin >> x2 >> y2;

	cout << solve() << "\n";
}

int main()
{
	int tc;
	for(scanf("%d", &tc); tc--;)
		proc();
	return 0;
}
