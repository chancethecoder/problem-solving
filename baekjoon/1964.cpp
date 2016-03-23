#include <cstdio>
const long long MOD = 45678;

long long solve(long long k)
{
	long long ret = 3 * k * k;
	ret += 5 * k + 2;
	ret /= 2;
	return ret % MOD;
}

void proc()
{
    long long n;
    scanf("%lld", &n);
    printf("%lld\n", solve(n));
}

int main()
{
    proc();
    return 0;
}
