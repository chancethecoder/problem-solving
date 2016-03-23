#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
struct pos{int x, y;};
const int MAX_N = 200000;
vector<pos> p;
int n;
int ans;
int eq;

bool cmp1(pos a, pos b)
{
    return (a.x == b.x ? a.y < b.y : a.x < b.x);
}

bool cmp2(pos a, pos b)
{
    return a.y < b.y;
}

void proc()
{
    cin >> n;
    p.resize(n);
    for(int i = 0; i < n; ++i)
    {
        scanf("%d %d", &p[i].x, &p[i].y);
    }

    sort(p.begin(), p.end(), cmp1);

    for(int i = 0; i < n - 1; ++i)
    {
        if(p[i].x == p[i + 1].x && p[i].y == p[i + 1].y)
            ++eq;
    }

    for(int i = 0; i < p.size(); ++i)
    {
        if(i < p.size() - 1 && p[i].x == p[i + 1].x)
        {
            int cnt = 2;
            ++i;
            while(i < p.size() - 1 && p[i].x == p[i + 1].x)
            {
                ++cnt;
                ++i;
            }

            ans += (cnt*(cnt-1)) / 2;
        }
    }

    sort(p.begin(), p.end(), cmp2);

    for(int i = 0; i < p.size(); ++i)
    {
        if(i < p.size() - 1 && p[i].y == p[i + 1].y)
        {
            ++i;
            int cnt = 2;
            while(i < p.size() - 1 && p[i].y == p[i + 1].y)
            {
                ++cnt;
                ++i;
            }

            ans += (cnt*(cnt-1)) / 2;
        }
    }

    ans -= eq;

    cout << ans << endl;
}

int main()
{
    proc();
    return 0;
}
