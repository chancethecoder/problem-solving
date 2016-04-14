#include <iostream>
#include <cstdio>

using namespace std;
const int MAX_N = 400;
int n, k, s;
int adj[MAX_N][MAX_N];

int solve()
{
    for(int k = 0; k < n; ++k)
    {
        for(int i = 0; i < n; ++i)
        {
            if(!adj[i][k]) continue;

            for(int j = 0; j < n; ++j)
            {
                if(i == j || adj[i][j] || !adj[k][j]) continue;
                if(adj[i][k] * adj[k][j] == -1) continue;

                adj[i][j] = adj[i][k];
            }
        }
    }
}

void proc()
{
    cin >> n >> k;

    for(int i = 0; i < k; ++i)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        adj[a - 1][b - 1] = 1;
        adj[b - 1][a - 1] = -1;
    }

    solve();

    cin >> s;

    for(int i = 0; i < s; ++i)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", -1 * adj[a - 1][b - 1]);
    }
}

int main()
{
    proc();
    return 0;
}
