#include <iostream>
#include <string>
using namespace std;
int n;
string s;

string check()
{
	int cnt[26] = {0};

	for(int i = 0; i < s.length(); ++i)
	{
		if(s[i] >= 'A' && s[i] <= 'Z') ++cnt[s[i] - 'A'];
		else if(s[i] >= 'a' && s[i] <= 'z') ++cnt[s[i] - 'a'];
	}

	int min_cnt = 4;

	for(int i = 0; i < 26; ++i)
		if(cnt[i] < min_cnt) min_cnt = cnt[i];

	if(min_cnt == 0) return "Not a pangram";
	else if(min_cnt == 1) return "Pangram!";
	else if(min_cnt == 2) return "Double pangram!!";
	else return "Triple pangram!!!";
}

void proc()
{
	cin >> n;
	cin.ignore();
	for(int i = 1; i <= n; ++i)
	{
		getline(cin, s);
		cout << "Case " << i << ": " << check() << endl;
	}
}

int main()
{
	proc();
	return 0;
}
