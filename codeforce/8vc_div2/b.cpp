#include <cstdio>
int n;
int a[200010];
int b[200010];

void init()
{
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
	for(int i = 0; i < n; ++i) scanf("%d", &b[i]);
}

char *solve()
{
	if(n <= 3) return "YES";

	for(int i = 0; i < n; ++i)
	{
		int a_idx = 0;
		int b_idx = i;
		if(a[a_idx] == 0) ++a_idx;
		if(b[b_idx] == 0) b_idx = (b_idx + 1) % n;

		while(a_idx < n && a[a_idx] == b[b_idx])
		{
			++a_idx;
			b_idx = (b_idx + 1) % n;

			if(a[a_idx] == 0) ++a_idx;
			if(b[b_idx] == 0) b_idx = (b_idx + 1) % n;
		}

		if(a_idx == n) return "YES";
	}

	return "NO";
}

int main()
{
	init();
	printf("%s\n", solve());
}
