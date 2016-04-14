#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;
const int MAX_N = 5000000;
int N, K;
int arr[MAX_N];

void swap(int &a, int &b) { int tmp = a; a = b; b = tmp;}

void solve(int i, int j)
{
    if(i >= j) return;
    int left = i - 1;
    int right = j + 1;
    int pivot = arr[(i + j) / 2];

    while(true)
    {
        while(arr[++left] < pivot);
        while(arr[--right] > pivot);

        if(left >= right) break;

        swap(arr[left], arr[right]);
    }

    if(K - 1 < left) solve(i, left - 1);
    else if(K - 1 > right) solve(right + 1, j);
}

void proc()
{
    cin >> N >> K;

    for(int i = 0; i < N; ++i)
        scanf("%d", &arr[i]);

    solve(0, N - 1);
    cout << arr[K - 1] << "\n";
}

int main()
{
    proc();
    return 0;
}
