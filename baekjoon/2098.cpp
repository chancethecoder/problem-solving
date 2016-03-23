#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int MAX_N = 16;
const int INF = 1e9;
int N;
int adj[MAX_N][MAX_N];
int cache[MAX_N][1 << MAX_N];

int solve(int i, int flag)
{
    if(__builtin_popcount(flag) == 1)
        return adj[i][__builtin_ctz(flag)];

    int &ret = cache[i][flag];
    if(ret != -1) return ret;

    ret = INF;

    for(int j = 0; j < N; ++j)
    {
        if(!adj[i][j] || !(flag & (1 << j))) continue;

        int tmp = adj[i][j] + solve(j, (flag & ~(1 << j)));
        if(ret > tmp) ret = tmp;
    }

    return ret;
}

void proc()
{
    memset(cache, -1, sizeof(cache));

    cin >> N;

    for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j)
    {
        cin >> adj[i][j];
    }

    cout << solve(0, (1 << N) - 1) << "\n";
}

int main()
{
    proc();
    return 0;
}
