#include <cstdio>
int n, k;

// Combination //

// recursive function
int combination(int n, int r) 
{
    if (r <= 0 || n <= r) return 1;
    return combination(n - 1, r) + combination(n - 1, r - 1);
}

// dynamic programming
int cache[30][30];
int combination(int n, int r)
{
	if(r <= 0 || n <= r) return 1;
	if(cache[n][r] != -1)
		return cache[n][r];
	return cache[n][r] = combination(n - 1, r) + combination(n - 1, r - 1);
}
