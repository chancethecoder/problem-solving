#include <iostream>
#include <cstdio>

using namespace std;
const int MAX_N = 200;
int N, lcs;
int arr[MAX_N];
int cache[MAX_N];

void proc()
{
    cin >> N;

    for(int i = 0; i < N; ++i)
        scanf("%d", &arr[i]);

    for(int i = 0; i < N; ++i)
        ++cache[i];

    lcs = 1;

    for(int i = 1; i < N; ++i) for(int j = 0; j < i; ++j)
        if(arr[j] < arr[i] && cache[i] < cache[j] + 1)
        {
            cache[i] = cache[j] + 1;
            if(lcs < cache[i]) lcs = cache[i];
        }

    cout << (N - lcs) << "\n";
}

int main()
{
    proc();
    return 0;
}
