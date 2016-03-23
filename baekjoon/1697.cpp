#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int INF = 10000;
int d[100010];

int bfs(int s, int e)
{
	memset(d, INF, sizeof(d));
	queue<int> q;
	q.push(s);
	d[s] = 0;
	while(!q.empty())
	{
		int here = q.front();
		int move = d[here];
		q.pop();
		if(here == e) return move;

		if(here > 0 && d[here-1] > move + 1)
		{
			q.push(here-1);
			d[here-1] = move + 1;
		}
		if(here < 100000 && d[here+1] > move + 1)
		{
			q.push(here+1);
			d[here+1] = move + 1;
		}
		if(here <= 50000 && d[here*2] > move + 1)
		{
			q.push(here*2);
			d[here*2] = move + 1;
		}
	}
}

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	printf("%d\n", bfs(n, k));
}
