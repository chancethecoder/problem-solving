#include <iostream>
#include <cstdio>

using namespace std;
const int MAX_K = 10000;
const int MAX_N = 100;
int n, k;
int coin[MAX_N];
int noc[MAX_K + 1];

void proc()
{
    scanf("%d %d", &n, &k);

    for(int i = 0; i < n; ++i) scanf("%d", &coin[i]);

    noc[0] = 1;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 1; j <= k; ++j)
        {
            if(j < coin[i]) continue;
            noc[j] += noc[j - coin[i]];
        }
    }

    printf("%d\n", noc[k]);
}

int main()
{
    proc();
    return 0;
}
