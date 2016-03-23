#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> blue;
vector<int> white;
vector<int> hate[102];
bool vis[102];
int n;

void dfs(int s, bool isblue)
{
	vis[s] = true;

	if(isblue) blue.push_back(s);
	else white.push_back(s);

	for(int i = 0; i < hate[s].size(); i++)
		if(!vis[hate[s][i]]) dfs(hate[s][i], !isblue);
}

int main()
{
	scanf("%d", &n);

	for(int i = 1, a; i <= n; i++)
	{
		scanf("%d", &a);
		for(int b; a--;)
		{
			scanf("%d", &b);
			hate[i].push_back(b);
		}
	}

	for(int i = 1; i <= n; i++)
	{
		if(!vis[i]) dfs(i, true);
	}

	sort(blue.begin(), blue.end());
	sort(white.begin(), white.end());

	int size = blue.size();
	printf("%d\n", size);
	for(int i = 0; i < size; i++) printf("%d ", blue[i]);
	size = white.size();
	printf("\n%d\n", size);
	for(int i = 0; i < size; i++) printf("%d ", white[i]);
	putchar(10);
}
