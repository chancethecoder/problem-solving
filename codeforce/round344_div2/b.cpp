#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

const int MAX_N = 5000;
int n, m, k;
int row[MAX_N], col[MAX_N];
int row_seq[MAX_N], col_seq[MAX_N];

void proc()
{
	scanf("%d %d %d", &n, &m, &k);

	for(int i = 1; i <= k; ++i)
	{
		int q, x, a;
		scanf("%d %d %d", &q, &x, &a);

		if(q == 1)
		{
			row[x - 1] = a;
			row_seq[x - 1] = i;
		}
		else
		{
			col[x - 1] = a;
			col_seq[x - 1] = i;
		}
	}

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			if(row_seq[i] < col_seq[j]) printf("%d ", col[j]);
			else printf("%d ", row[i]);
		}
		putchar(10);
	}
}

int main()
{
	proc();
	return 0;
}
