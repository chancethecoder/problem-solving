#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MOD = 9901;
int cache[14*14][1<<14];
int n, m;

int solve(int pos, int state)
{
    if(pos >= n*m && state == 0) return 1;
    if(pos >= n*m) return 0;

    int &ret = cache[pos][state];
    if(ret != -1) return ret;

    if(state & 1)
        return ret = solve(pos + 1, state >> 1) % MOD;

    ret = solve(pos + 1, (state >> 1) | (1 << m - 1));

    if((pos % m) != (m - 1) && (state & 2) == 0)
        ret += solve(pos + 2, state >> 2);

    return ret %= MOD;
}

void proc()
{
    memset(cache, -1, sizeof(cache));
    cin >> n >> m;
    cout << solve(0, 0) << endl;
}

int main()
{
    proc();
    return 0;
}
