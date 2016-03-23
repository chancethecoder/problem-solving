#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;
const int MAX_N = 500000;
int n, m;
int idx;
string name[MAX_N];
string res[MAX_N];
string in;

bool binary(int l, int r)
{
    if(l > r) return false;

    int mid = (l + r) / 2;

    if(name[mid] == in) return true;

    if(name[mid] < in) return binary(mid + 1, r);
    else return binary(l, mid - 1);
}

void proc()
{
    cin >> n >> m;

    for(int i = 0; i < n; ++i)
        cin >> name[i];

    sort(name, name + n);

    for(int i = 0; i < m; ++i)
    {
        cin >> in;

        if(binary(0, n - 1))
            res[idx++] = in;
    }

    sort(res, res + idx);

    cout << idx << "\n";
    for(int i = 0; i < idx; ++i)
        cout << res[i] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    proc();
    return 0;
}
