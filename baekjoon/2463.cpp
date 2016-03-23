#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX_N = 100000;
const int MOD = 1000000000;
int n, m;
vector<pair<int, int> > adj[MAX_N];

bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
}

int kruskal(int u, int v)
{

}

void proc()
{
    cin >> n >> m;

    for(int i = 0; i < m; ++i)
    {
        int a, b, w;
        adj[a].push_back(make_pair(b, w));
        adj[b].push_back(make_pair(a, w));
    }

    sort(adj, adj + n, compare);

    cout << ans << "\n";
}

int main()
{
    proc();
    return 0;
}
