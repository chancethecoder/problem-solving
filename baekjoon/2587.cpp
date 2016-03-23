#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

void proc()
{
    int a[5], ave = 0, median = 0;
    for(int i = 0; i < 5; ++i)
    {
        cin >> a[i];
        ave += a[i];
    }

    ave /= 5;
    sort(a, a + 5);

    cout << ave << endl << a[2] << endl;
}

int main()
{
    proc();
    return 0;
}
