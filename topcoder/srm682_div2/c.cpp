#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <string>
#define max(a,b) ((a)<(b)?(b):(a))
using namespace std;

class FriendlyRobot{
public:
	vector<pair<int, int> > pos;
	int cache[310][310];
	int len;

	int dp(int i, int j)
	{
		if(i > len - 1) return 0;
		if(j <= 0) return 0;

		int &ret = cache[i][j];
		if(ret != -1) return ret;

		ret = 0;
		for(int k = i; k < len; k++)
		{
			int dist = abs(pos[k].first - (i ? pos[i - 1].first : 0)) + abs(pos[k].second - (i ? pos[i - 1].second : 0));

			if(dist % 2 == 1) continue;
			
			ret = max(ret, dp(k + 1, j - dist / 2) + 1);
		}

		return ret;
	}

	int findMaximumReturns(string ins, int allowed)
	{
		for(int i = 0; i < 301; i++) memset(cache[i], -1, sizeof(cache[i]));
		
		len = ins.length();
		int x = 0, y = 0;
		for(int i = 0; i < len; i++)
		{
			if(ins[i] == 'U') y++;
			if(ins[i] == 'R') x++;
			if(ins[i] == 'D') y--;
			if(ins[i] == 'L') x--;
			pos.push_back(make_pair(x, y));
		}

		return dp(0, allowed) + 1;
	}
};
