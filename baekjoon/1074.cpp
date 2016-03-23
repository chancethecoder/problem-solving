#include <iostream>
#include <cstdio>

using namespace std;

int solve(int n, int r, int c)
{
    if(n == 0) return 0;

    int half = 1 << (n - 1);
    int space = half * half;

    if(half <= r && half <= c)
        return 3 * space + solve(n - 1, r - half, c - half);
    else if(half <= r)
        return 2 * space + solve(n - 1, r - half, c);
    else if(half <= c)
        return space + solve(n - 1, r, c - half);
    else
        return solve(n - 1, r, c);
}

void proc()
{
    int n, r, c;
    while(cin >> n >> r >> c)
        cout << solve(n, r, c) << endl;
}

int main()
{
    proc();
    return 0;
}
