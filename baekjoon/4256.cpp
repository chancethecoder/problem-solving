#include <cstdio>
#include <algorithm>
using namespace std;
int pre[1010];
int in[1010];
int n;

void post(int i, int j, int a, int b)
{
	if(i > j) return;
/*	if(i == j)
	{
		printf("%d ", pre[i]);
		return;
	}
*/
	int idx = find(in + a, in + b + 1, pre[i]) - (in + a);

	post(i+1, i+idx, a, a+idx-1);
	post(i+idx+1, j, a+idx+1, b);
	printf("%d ", pre[i]);
}

int main()
{
	int tc;
	for(scanf("%d", &tc); tc--;)
	{
		scanf("%d", &n);
		for(int i = 0; i < n; i++) scanf("%d", &pre[i]);
		for(int i = 0; i < n; i++) scanf("%d", &in[i]);
		post(0, n-1, 0, n-1);
		puts("");
	}
}
