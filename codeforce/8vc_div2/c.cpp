#include <iostream>
using namespace std;

int main()
{
	long long s, x;
	cin >> s >> x;

	int ans = 0;
	long long a = 1, b = s - 1;

	while(a < b)
	{
		if((a ^ b) == x) ans++;
		a++, b--;
	}

	cout << ans*2 << endl;
}
