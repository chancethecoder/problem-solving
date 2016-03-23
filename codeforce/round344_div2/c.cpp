#include <cstdio>
#include <algorithm>
using namespace std;
int n, m;
int a[200001];

void proc()
{
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
	for(int i = 0; i < m; ++i)
	{
		int t, r;
		scanf("%d %d", &t, &r);
		if(t == 1) sort(a, a + r);
		else sort(a, a + r, [](int a, int b){return a > b;});
	}

	for(int i = 0; i < n; ++i) printf("%d ", a[i]);
}

int main()
{
	proc();
	return 0;
}
