#include <iostream>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);

	int n, m;
	int delay[100010];
	cin >> n >> m;

	for(int i = 0; i < n; i++) cin >> delay[i];

	int low = delay[0] * (m / n);
	int high = delay[n-1] * (m / n);
	int sol = 1e9;

	while(low < high)
	{
		int average = (low + high) / 2;
		int count = 0;
		for(int i = 0; i < n; i++) count += average / delay[i];

		if(count > m) high = average - 1;
		else 
		{
			if(count == m) sol = min(sol, average);
			low = average + 1;
		}
	}

	cout << sol << endl;
}
