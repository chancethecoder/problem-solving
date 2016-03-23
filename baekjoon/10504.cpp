#include <iostream>
#include <cstdio>

using namespace std;
int N;
/*
void proc()
{
    scanf("%d", &N);

    int sum = 0;
    int tail = N / 2;

    for(int head = N / 2; head > 0; --head)
    {
        sum += head;

        while(sum > N)
        {
            sum -= tail--;
        }

        if(sum == N)
        {
            printf("%d = ", N);
            for(int i = head; i < tail; ++i)
            {
                printf("%d + ", i);
            }
            printf("%d\n", tail);

            return;
        }
    }

    puts("IMPOSSIBLE");
}
*/

void proc()
{
    scanf("%d", &N);

    if(N % 2 && N != 1)
    {
        printf("%d = %d + %d\n", N, N / 2, N / 2 + 1);
        return;
    }

    for(int k = 2; k * (k + 1) / 2 <= N; ++k)
    {
        bool mod = (N % k) != 0;
        int median = N / k;
        int sum = mod ? 0 : median;
        int iter = 0;

        while(sum < N)
        {
            sum += 2 * median + mod;
            ++iter;
        }

        if(sum == N)
        {
            printf("%d = ", N);
            for(int i = median - iter + mod; i < median + iter; ++i)
                printf("%d + ", i);
            printf("%d\n", median + iter);
            return;
        }
    }

    puts("IMPOSSIBLE");
}

int main()
{
    int tc;
    for(scanf("%d", &tc); tc--;)
        proc();
    return 0;
}
