#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
const int MAX_I = 300;
const int INF = 1000000007;
int l;
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
pair<int, int> start;
pair<int, int> end;
int mat[MAX_I][MAX_I];

int solve()
{
	for(int i = 0; i < l; ++i)
		for(int j = 0; j < l; ++j)
			mat[i][j] = INF;

	queue<pair<int, int> > q;
	int y = start.first;
	int x = start.second;
	q.push(make_pair(y, x));
	
	mat[y][x] = 0;

	while(!q.empty())
	{
		y = q.front().first;
		x = q.front().second;
		q.pop();

		if(y == end.first && x == end.second)
			return mat[y][x];

		for(int k = 0; k < 8; ++k)
		{
			int ny = y + dy[k];
			int nx = x + dx[k];

			if(ny < 0 || ny >= l || nx < 0 || nx >= l) continue;

			if(mat[ny][nx] > mat[y][x] + 1)
			{
				mat[ny][nx] = mat[y][x] + 1;
				q.push(make_pair(ny, nx));
			}
		}
	}
}

void proc()
{
	int tc;
	for(scanf("%d", &tc); tc--; )
	{
		cin >> l;
		int a, b;
		cin >> a >> b;
		start.first = b, start.second = a;
		cin >> a >> b;
		end.first = b, end.second = a;

		printf("%d\n", solve());
	}

}

int main()
{
	proc();
	return 0;
}
