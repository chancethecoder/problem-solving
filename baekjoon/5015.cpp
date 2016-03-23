#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;
const int MAX_LEN = 100;
int cache[MAX_LEN + 1][MAX_LEN + 1];
int p_idx;
string W, S;

bool match(int w, int s)
{
	if(w > W.size() || s > S.size()) return false;
	if(W[w] != '*' && W[w] != S[s]) return false;
	if((w == W.size() - 1 || w >= p_idx) && s == S.size() - 1) return true;

	int &ret = cache[w][s];
	if(ret != -1) return ret;
	
	ret = false;

	if(W[w] == '*')
	{
		if(match(w, s + 1)) ret = true;
		if(match(w + 1, s)) ret = true;
	}

	if(match(w + 1, s + 1)) ret = true;

	return ret;
}

void proc()
{
	int n;
	cin >> W >> n;

	p_idx = W.size() - 1;
	while(p_idx && W[p_idx] == '*') --p_idx;

	while(n--)
	{
		cin >> S;
		for(int i = 0; i < MAX_LEN + 1; ++i) 
			memset(cache[i], -1, sizeof(cache[i]));	
		if(match(0, 0)) 
			cout << S << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	proc();
	return 0;
}
