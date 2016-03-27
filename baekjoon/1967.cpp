#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
const int MAX_N = 10000;
int n;
vector<pair<int, int> > adj[MAX_N + 1];
int parent[MAX_N + 1];
int diameter[MAX_N + 1];
int path[MAX_N + 1];

void construct(int i)
{
    int path1 = 0, path2 = 0;

    for(int v = 0; v < adj[i].size(); ++v)
    {
        int child = adj[i][v].first;
        int cur_len = path[child] + adj[i][v].second;

        if(cur_len > path[i]) path[i] = cur_len;

        if(cur_len > path1)
        {
            path2 = path1;
            path1 = cur_len;
        }
        else if(cur_len > path2)
            path2 = cur_len;
    }

    diameter[i] = path1 + path2;

    if(i != 1) construct(parent[i]);
}

void proc()
{
    cin >> n;

    for(int i = 0; i < n - 1; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b, c));
        parent[b] = a;
    }

    for(int i = 1; i <= n; ++i)
    {
        if(adj[i].empty() && parent[i])
            construct(parent[i]);
    }

    int ans = 0;

    for(int i = 1; i <= n; ++i)
        if(ans < diameter[i]) ans = diameter[i];

    cout << ans << "\n";
}

int main()
{
    proc();
    return 0;
}
