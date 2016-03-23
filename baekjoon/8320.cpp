#include <iostream>
#include <cstdio>

using namespace std;
int n;
int ans;

void proc()
{
    cin >> n;

    for(int i = 1; i <= n; ++i)
        for(int j = i; i*j <= n; ++j) ++ans;

    cout << ans << endl;
}

int main()
{
    proc();
    return 0;
}
