#include <iostream>
#include <cstdio>

using namespace std;
int a, b;
int ans;

void proc()
{
    cin >> a >> b;

    while((a > 0) && (b > 0))
    {
        if(a == 1 && b == 1) break;
        
        if(a > b)
        {
            a -= 2;
            ++b;
        }
        else
        {
            b -= 2;
            ++a;
        }
        ++ans;
    }

    cout << ans << endl;
}

int main()
{
    proc();
    return 0;
}
