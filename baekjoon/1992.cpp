#include <iostream>
#include <string>
using namespace std;
const int MAX_N = 64;
int n;
string s[MAX_N];

string quad(int x1, int x2, int y1, int y2)
{
	if(x1 == x2) return s[y1].substr(x1, 1);

	int mx = (x2 + x1) / 2;
	int my = (y2 + y1) / 2;

	string s1 = quad(x1, mx, y1, my);
	string s2 = quad(mx + 1, x2, y1, my);
	string s3 = quad(x1, mx, my + 1, y2);
	string s4 = quad(mx + 1, x2, my + 1, y2);

	if(s1 == s2 && s2 == s3 && s3 == s4)
	{
		bool is_equal = true;
		for(int i = 0; is_equal && i < s1.length() - 1; ++i)
			if(s[i] != s[i + 1]) is_equal = false;
		
		if(is_equal) return s1;
	}

	return "(" + s1 + s2 + s3 + s4 + ")";
}

void proc()
{
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> s[i];
	cout << quad(0, n - 1, 0, n - 1) << endl;
}

int main()
{
	proc();
	return 0;
}
