#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
int n;
long long ans;
map<int, int> depth;

void proc()
{
    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        int x;
        scanf("%d", &x);

        map<int, int>::iterator iter = depth.lower_bound(x);

        int d = 0;
        if(iter != depth.end()) d = max(d, iter->second + 1);
        if(iter != depth.begin()) d = max(d, (--iter)->second + 1);

        depth[x] = d;
        
        ans += d;
        printf("%lld\n", ans);
    }
}

int main() {
    proc();
    return 0;
}
