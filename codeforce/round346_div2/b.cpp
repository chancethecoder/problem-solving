#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
const int MAX_M = 10000;
int n, m;
vector<pair<int, string> > region[MAX_M + 1];

bool cmp(const pair<int, string> &a, const pair<int, string> &b)
{
    return a.first > b.first;
}

void proc()
{
    cin >> n >> m;

    for(int i = 0; i < n; ++i)
    {
        string name;
        int where, score;

        cin >> name >> where >> score;

        region[where].push_back(make_pair(score, name));
    }

    for(int here = 1; here <= m; ++here)
    {
        sort(region[here].begin(), region[here].end(), cmp);

        if(region[here].size() > 2
            && region[here][1].first == region[here][2].first)
        {
            puts("?");
        }
        else
        {
            cout << region[here][0].second << " " << region[here][1].second << "\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    proc();
    return 0;
}
