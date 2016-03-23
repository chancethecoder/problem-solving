#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MAX_LEN = 100;
int cache[MAX_LEN+1][MAX_LEN+1];
int p_idx;
string pattern, word;
vector<string> ans;

bool match(int p, int w)
{
	if(p >= pattern.size() || w >= word.size()) return false;

	if(pattern[p] != '*' &&
		pattern[p] != '?' && 
		pattern[p] != word[w]) return false;
	
	if((p >= p_idx || p == pattern.size() - 1) && w == word.size() - 1) return true;

	int &ret = cache[p][w];
	if(ret != -1) return ret;

	ret = false;

	if(pattern[p] == '*')
	{
		if(match(p + 1, w)) ret = true;
		if(match(p, w + 1)) ret = true;
	}

	if(match(p + 1, w + 1)) ret = true;

	return ret;
}

void proc()
{
	int tc, n;
	for(scanf("%d", &tc); tc--; )
	{
		ans.clear();
		cin >> pattern;
		p_idx = pattern.size() - 1;
		while(p_idx && pattern[p_idx] == '*') --p_idx;

		for(scanf("%d", &n); n--; )
		{
			for(int i = 0; i < MAX_LEN + 1; ++i)
				memset(cache[i], -1, sizeof(cache[i]));
			cin >> word;
			if(match(0, 0)) ans.push_back(word);
		}

		sort(ans.begin(), ans.end());
		for(int i = 0; i < ans.size(); ++i)
			cout << ans[i] << endl;
	}
}

int main()
{
	proc();
	return 0;
}
