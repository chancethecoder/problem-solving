#include <cstdio>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
string s1, s2;

void solve()
{
	int len = s1.length();

	cout << "Distances: ";

	for(int i = 0; i < len; ++i)
	{
		cout << (s2[i] - s1[i] + 26) % 26 << " ";
	}

	cout << endl;
}

void proc()
{
	int tc;
	for(scanf("%d", &tc); tc--; )
	{
		cin >> s1 >> s2;
		solve();
	}
}

int main()
{
	proc();
	return 0;
}
