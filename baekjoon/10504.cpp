#include <iostream>
#include <cstdio>

using namespace std;
int N;

void proc()
{
    scanf("%d", &N);

    if(__builtin_popcount(N) == 1)
        puts("IMPOSSIBLE");

    else if(N % 2)
    {
        int k = N / 2;
        printf("%d = %d + %d\n", N, k, k + 1);
    }

    else
    {
        for(int k = 2; k * (k + 1) <= 2 * N; ++k)
        {
            int x = N / k - (k - 1) / 2;

            if(2 * k * x + (k - 1) * k == 2 * N)
            {
                printf("%d = ", N);
                for(int i = x; i < x + k - 1; ++i)
                    printf("%d + ", i);
                printf("%d\n", x + k - 1);
                return;
            }
        }
    }

}

int main()
{
    int tc;
    for(scanf("%d", &tc); tc--;)
        proc();
    return 0;
}
