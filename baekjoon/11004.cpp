#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int MAX_N = 5000000;
int N, K;
int arr[MAX_N];

void proc()
{
    cin >> N >> K;

    for(int i = 0; i < N; ++i)
        scanf("%d", &arr[i]);

    nth_element(arr, arr + K - 1, arr + N);

    cout << arr[K - 1] << "\n";
}

int main()
{
    proc();
    return 0;
}
