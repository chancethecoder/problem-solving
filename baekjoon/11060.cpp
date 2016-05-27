#include <iostream>
#include <cstdio>
#include <cstring>
#define min(a,b) ((a)<(b)?(a):(b))

using namespace std;
const int MAX_N = 1000;
const int INF = 1000007;
int N;
int A[MAX_N];
int cache[MAX_N];

void proc()
{
    cin >> N;

    for(int i = 0; i < N; ++i)
        scanf("%d", &A[i]);

    memset(cache, INF, sizeof(cache));

    cache[0] = 0;

    for(int i = 0; i < N; ++i)
    {
        for(int j = 1; j <= A[i]; ++j)
        {
            if(i + j >= N) break;

            cache[i + j] = min(cache[i + j], cache[i] + 1);
        }
    }

    if(cache[N - 1] >= INF) cache[N - 1] = -1;

    cout << cache[N - 1] << "\n";
}

int main()
{
    proc();
    return 0;
}
