#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int cache[21][21][21];

int solve(int a, int b, int c)
{
    if(a <= 0 || b <= 0 || c <= 0) return 1;
    if(a > 20 || b > 20 || c > 20) return solve(20, 20, 20);

    int &ret = cache[a][b][c];
    if(ret != -1) return ret;

    if(a < b && b < c)
        ret = solve(a, b, c-1) + solve(a, b-1, c-1) - solve(a, b-1, c);
    else
        ret = solve(a-1, b, c) + solve(a-1, b-1, c) + solve(a-1, b, c-1) - solve(a-1, b-1, c-1);

    return ret;
}

void proc(int a, int b, int c)
{
    memset(cache, -1, sizeof(cache));
    printf("w(%d, %d, %d) = %d\n", a, b, c, solve(a, b, c));
}

int main()
{
    for(int a, b, c; scanf("%d %d %d", &a, &b, &c); )
    {
        if(a == -1 && b == -1 && c == -1) break;
        proc(a, b, c);
    }
    return 0;
}
