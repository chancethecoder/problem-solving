#include <iostream>
#include <cstdio>

using namespace std;

bool solve(long long x)
{
    long long upper = x / 2;
    int ans = 0;

    for(long long i = 2; i <= upper; ++i)
    {
        if(x % i == 0) ++ans;
    }

    return ans % 2;
}

void proc()
{
    int tc;
    for(scanf("%d", &tc); tc--; )
    {
        long long x;
        cin >> x;
        cout << solve(x) << " ";
    }
}

int main()
{
    proc();
    return 0;
}
