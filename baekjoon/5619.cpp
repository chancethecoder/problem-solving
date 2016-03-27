#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;
const int MAX_N = 10000;
int n;
string s[MAX_N];

/*
10
10000 9999 1 5555 1000 444  1001 3333 1111 2222
10
444 1 555 1111 9999 2222 3333 1000 5555 10000
10
1 444 555 666 1000 2222 3333 5555 9999 10000
*/

bool cmp(const string &a, const string &b)
{
	if(a.size() == b.size()) return a < b;
	return a.size() < b.size();
}

void proc()
{
	cin >> n;

	for(int i = 0; i < n; ++i)
		cin >> s[i];

	sort(s, s + n, cmp);

	string ss[12];
	int idx = 0;
	for(int i = 0; i < n && i <= 3; ++i)
	{
		for(int j = 0; j < n && j <= 3; ++j)
		{
			if(i == j) continue;
			ss[idx++] = s[i] + s[j];
		}
	}

	sort(ss, ss + idx, cmp);
	cout << ss[2] << "\n";
}

int main()
{
	proc();
	return 0;
}
