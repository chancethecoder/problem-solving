#include <cstdio>
#include <string>

struct EqualSubstrings2{

	int get(String s)
	{
		int ans = 0;
		int length = s.length();

		for(int len = 1; len < length; len++)
		{
			for(int left = 0; left < length - 2*len; left++)
			{
				for(int right = left + len; right < length - len; right++)
				{
					string l_str = s.substring(left, left + len);
					string r_str = s.substring(right, right + len);

					if(l_str == r_str) ans++;
				}
			}
		}

		return ans;
	}
};
