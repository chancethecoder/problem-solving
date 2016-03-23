#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int arr[1010];
vector<int> V;

// Longest Increasig Subsequence //
void proc()
{
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> arr[i];
	V.push_back(arr[0]);

	for(int i = 1; i < n; ++i)
	{
		if(V[V.size() - 1] < arr[i])
			V.push_back(arr[i]);
		else
			V[lower_bound(V.begin(), V.end(), arr[i]) - V.begin()] = arr[i];
	}

	cout << V.size() << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	proc();
}
