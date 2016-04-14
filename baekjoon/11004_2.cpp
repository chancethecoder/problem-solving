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
    while(i < j)
    {
        int left = i;
        int right = j;
        int pivot = arr[(i + j) / 2];

        while(left < right)
        {
            if(arr[left] >= pivot)
            {
                swap(arr[left], arr[right]);
                --right;
            }
            else
                ++left;
        }

        if(arr[left] > pivot) --left;

        if(K - 1 <= left) j = left;
        else i = left + 1;
    }
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
