#include <cstdio>
#include <iostream>
#define max(a,b) ((a)<(b)?(b):(a))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int notSame[368], f_cnt[368], m_cnt[368];
int n;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=0;i<n;i++)
	{
		char s;
		int a, b;
		cin >> s >>  a >> b;

		for(int j=a;j<=b;j++)
			if(s == 'M') {notSame[j]++, m_cnt[j]++;}
			else {notSame[j]--, f_cnt[j]++;}
	}

	int sol = 0;
	for(int i=1;i<=366;i++)
		if(!notSame[i]) sol = max(sol, 2*min(f_cnt[i], m_cnt[i]));

	cout << sol;
}
