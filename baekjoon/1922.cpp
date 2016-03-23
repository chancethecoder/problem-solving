#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
const int MAX_V = 1000;
const int INF = 1000000007;
vector<pair<int, int> > adj[MAX_V];
vector<bool> added(MAX_V, false);
vector<int> minWeight(MAX_V, INF);
int n, m;

int prim()
{
    int ans = 0;
    minWeight[0] = 0;

    for(int i = 0; i < n; ++i)
    {
        int u = -1;
        for(int v = 0; v < n; ++v)
        {
            if(!added[v] && (u == -1 || minWeight[v] < minWeight[u]))
                u = v;
        }

        ans += minWeight[u];
        added[u] = true;

        for(int i = 0; i < adj[u].size(); ++i)
        {
            int v = adj[u][i].first;
            int weight = adj[u][i].second;

            if(!added[v] && (minWeight[v] > weight))
                minWeight[v] = weight;
        }
    }

    return ans;
}

void proc()
{
    cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a-1].push_back(make_pair(b-1, w));
        adj[b-1].push_back(make_pair(a-1, w));
    }
    cout << prim() << endl;
}

int main()
{
    proc();
    return 0;
}
