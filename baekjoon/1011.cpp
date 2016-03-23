#include <iostream>
#include <cstdio>

using namespace std;
const int INF = 1e9;
const int dhop[] = {-1, 0, 1};
int x, y;

int solve(int cur, int hop, int cnt)
{
    if(cur > y - x) return INF;
    if(cur == y - x - 1 && hop == 1) return cnt;

    int ret = INF;

    for(int k = 0; k < 3; ++k)
    {
        int nhop = hop + dhop[k];
        if(nhop < 1) continue;

        int tmp = solve(cur + hop, nhop, cnt + 1);

        if(ret > tmp) ret = tmp;
    }

    return ret;
}

void proc()
{

    cin >> x >> y;
    cout << solve(0, 0, 0) << "\n";
}

int main()
{
    int tc;
    for(scanf("%d", &tc); tc--; )
        proc();
    return 0;
}
