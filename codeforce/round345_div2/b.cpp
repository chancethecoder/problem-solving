#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX_N = 1000;
bool added[MAX_N];
vector<int> a;
vector<int> b[MAX_N];
int n;
int ans;
int idx;

void proc()
{
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; ++i) scanf("%d", &a[i]);

    sort(a.begin(), a.end());

    while(!a.empty())
    {
        for(int i = 0; i < a.size() && !a.empty();)
        {
            int cur = a[i];
            b[idx].push_back(cur);
            a.erase(a.begin() + i);
            while(i < a.size() && cur == a[i]) ++i;
        }

        ++idx;
    }

    for(int i = 0; i < idx; ++i)
        ans += b[i].size() - 1;

    cout << ans << endl;
}

int main()
{
    proc();
    return 0;
}
