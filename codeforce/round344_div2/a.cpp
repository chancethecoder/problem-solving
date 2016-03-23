#include <cstdio>
const int MAX_N = 1000;
int n;
int a[MAX_N + 1];
int b[MAX_N + 1];

void proc()
{
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
	for(int i = 0; i < n; ++i) scanf("%d", &b[i]);

	int ans = 0;

	for(int l = 0; l < n - 1; ++l) for(int r = n - 1; r > l; --r)
	{
		int a_or = a[l];
		for(int k = l+1; k <= r; ++k) a_or |= a[k];

		int b_or = b[l];
		for(int k = l+1; k <= r; ++k) b_or |= b[k];

		if(ans < a_or + b_or) ans = a_or + b_or;
	}

	printf("%d\n", ans);
}

int main()
{
	proc();
	return 0;
}
