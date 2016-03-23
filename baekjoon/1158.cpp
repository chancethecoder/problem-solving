#include <iostream>
#include <cstdio>

using namespace std;
const int MAX_N = 5000;
int N, M;
int josephus[MAX_N+1][MAX_N+1];

int solve(int n, int m)
{
    if(n == 1) return 1;

    int &ret = josephus[n][m];
    if(ret != 0) return ret;

    return ret = ((solve(n - 1, m) + m - 1) % n) + 1;
}

void proc()
{
    cin >> N >> M;
    solve(N, M);

    cout << "<" << josephus[1][M];
    for(int i = 2; i <= N; ++i)
        cout << ", " << josephus[i][M];
    cout << ">\n";
}

int main()
{
    proc();
    return 0;
}
