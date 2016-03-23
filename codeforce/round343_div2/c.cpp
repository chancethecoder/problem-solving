#include <cstdio>
#define mod 1000000007
int n, m, cnt, sol;
char str[100010];

int main()
{
	scanf("%d %d", &n, &m);
	getchar();
	scanf("%s", str);

	for(int i=0;i<m;i++)
		if(str[i] == '(') cnt++;
		else cnt--;

	if(cnt > n - m || -cnt > n - m) sol = 0;
	else if(n == m) sol = 1;
	else
	{
		int rest = n - m;

		for(int l = 0, int r = rest - l ; l <= rest; l++)
		{

		}
	}

	printf("%d\n", sol);
}
