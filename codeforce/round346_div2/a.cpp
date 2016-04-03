#include <iostream>
#include <cstdio>

using namespace std;

void proc()
{
    int n, a, b;
    cin >> n >> a >> b;

    a += b;

    if(a <= 0)
    {
        while(a <= 0) a += n;
    }
    else
    {
        while((a - n) > 0) a -= n;
    }

    cout << a << "\n";
}

int main()
{
    proc();
    return 0;
}
