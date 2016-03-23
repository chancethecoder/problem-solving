#include <iostream>
#include <cstdio>
using namespace std;
const int MAX_N = 100;
int n, m;
int arr[MAX_N];

void hand_over(int k)
{
    for(int i = 0; i < n - 1; ++i)
    {
        if(arr[i] % k > arr[i + 1] % k)
        {
            int tmp = arr[i + 1];
            arr[i + 1] = arr[i];
            arr[i] = tmp;
        }
    }
}

void proc()
{
    cin >> n >> m;

    for(int i = 0; i < n; ++i)
        cin >> arr[i];

    for(int k = 1; k <= m; ++k)
        hand_over(k);

    for(int i = 0; i < n; ++i)
        cout << arr[i] << endl;
}

int main()
{
    proc();
    return 0;
}
