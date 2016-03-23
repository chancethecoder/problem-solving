#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

void post(const vector<int> &pre, const vector<int> &in, 
		int pi, int pj, int ini, int inj)
{
	if(pi >= pre.size()) return;

	int idx = find(in.begin(), in.end(), pre[pi]) - in.begin();
	post(pre, in, pi+1, idx+1, ini, idx);
	post(pre, in, idx+1, pj, idx+1, pj);
	printf("%d ", pre[pi]);
}

void proc()
{
	int tc, n;
	for(scanf("%d", &tc); tc--; )
	{
		scanf("%d", &n);
		vector<int> pre; pre.resize(n);
		vector<int> in; in.resize(n);
		for(int i = 0; i < n; i++) scanf("%d", &pre[i]);
		for(int i = 0; i < n; i++) scanf("%d", &in[i]);
		post(pre, in, 0, n-1, 0, n-1);
		putchar(10);
	}
}

int main()
{
	proc();
}
