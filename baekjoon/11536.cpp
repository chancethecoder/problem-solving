#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int n;
string s[20];

string check()
{
	bool order = s[0] <= s[1];
	int idx = 1;

	while(idx < n - 1 && (s[idx] < s[idx + 1] == order)) ++idx;

	return idx < n - 1 ? "NEITHER" : order ? "INCREASING" : "DECREASING";
}

void proc()
{
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> s[i];
	cout << check() << endl;
}

int main()
{
	proc();
	return 0;
}
