#include <vector>
#include <cstdlib>
using namespace std;

struct MoveStonesEasy{

	int get(vector<int> a, vector<int> b)
	{
		int n = a.size();
		vector<int> diff(n, 0);
		int a_sum = 0, b_sum = 0;

		for(int i = 0; i < n; i++) 
		{
			a_sum += a[i];
			b_sum += b[i];
			diff[i] = a[i] - b[i];
		}

		if(a_sum != b_sum) return -1;

		int ans = 0;

		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(i == j) continue;
				if(diff[i] * diff[j] > 0) continue;

				while(diff[i] && diff[j])
				{
					diff[i] > 0 ? --diff[i] : ++diff[i];
					diff[j] > 0 ? --diff[j] : ++diff[j];

					ans += j - i;
				}
			}
		}

		return ans;
	}
};
