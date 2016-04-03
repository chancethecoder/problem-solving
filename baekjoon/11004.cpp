#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;
const int MAX_N = 5000000;
int n, k;
int arr[MAX_N];

void swap(int &a, int &b) { int tmp = a; a = b; b = tmp;}

int solve()
{
    int i = 0;
    int j = n - 1;

    while(i < j)
    {
        int left = i;
        int right = j;
        int pivot = arr[(rand() % (j - i + 1)) + i];

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

        if(k - 1 <= left) j = left;
        else i = left + 1;
    }

    return arr[k - 1];
}

void proc()
{
    srand(time(0));

    cin >> n >> k;

    for(int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    cout << solve() << "\n";
}

int main()
{
    proc();
    return 0;
}
