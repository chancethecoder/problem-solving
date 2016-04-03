#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int MAX_N = 100000;
int n, m;
int arr[MAX_N];

void proc()
{
    cin >> n >> m;

    for(int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    sort(arr, arr + n);

    for(int i = 1; i <= 1000000000; ++i)
    {
        if(m < i) break;

        if(binary_search(arr, arr + n, i)) continue;

        printf("%d ", i);
        m -= i;
    }
}

int main()
{
    proc();
    return 0;
}
