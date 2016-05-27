#include <iostream>
#include <cstdio>

using namespace std;
const int MAX_N = 100;
const long long MOD = 1000000000;
int n;
long long cache[MAX_N + 1];

/*
9876543210

10123456789
98765432101
89876543210

210123456789
898765432101
789876543210
989876543210

*/

void proc()
{
    cin >> n;

    cache[10] = 1;

    long long sum = 0;
    for(int i = 1; i <= 40; ++i)
        sum += cache[i];
    cout << sum << "\n";

    cout << cache[n] << "\n";
}

int main()
{
    proc();
    return 0;
}
