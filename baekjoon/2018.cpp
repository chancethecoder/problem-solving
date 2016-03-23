#include <iostream>
#include <cstdio>

using namespace std;
int n;

int solve(int k)
{
    if(n < (k * (k + 1)) / 2) return 0;

    int median = n / k;
    int sum = 0;
    bool f = (n % k == 0);

    if(f) sum += median;

    while(sum < n) sum += 2 * median + !f;

    return solve(k + 1) + (sum == n);
}

void proc()
{
    cin >> n;
    cout << solve(1) << "\n";
}

int main()
{
    proc();
    return 0;
}
