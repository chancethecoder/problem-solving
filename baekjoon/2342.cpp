#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#define min(a,b) ((a)<(b)?(a):(b))

using namespace std;
const int MAX_N = 100000;
int cache[MAX_N][5][5];
int len;
vector<int> seq;

int work(int a, int b)
{
	if(!a) return 2;
	if(a == b) return 1;
	if(abs(a - b) == 2) return 4;
	return 3;
}

int solve(int pos, int left, int right)
{
	if(len <= pos) return 0;

	int &ret = cache[pos][left][right];
	if(ret != -1) return ret;

	ret = solve(pos + 1, left, seq[pos]) + work(right, seq[pos]);
	ret = min(ret, solve(pos + 1, seq[pos], right) + work(left, seq[pos]));

	return ret;
}

void proc()
{
	memset(cache, -1, sizeof(cache));

	for(int i; scanf("%d", &i) && i;)
		seq.push_back(i);

	len = seq.size();

	cout << solve(0, 0, 0) << "\n";
}

int main()
{
	proc();
	return 0;
}
