#include <iostream>
#include <cstdio>

using namespace std;
const int MAX_N = 50000;
int n, m;
int parent[MAX_N + 1];
int height[MAX_N + 1];

int find(int a, int b)
{
    if(a == b) return a;

    if(height[a] < height[b])
        return find(a, parent[b]);

    else
        return find(parent[a], b);
}

void proc()
{
    cin >> n;

    for(int i = 1; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        if(a > b)
        {
            int tmp = a;
            a = b;
            b = tmp;
        }
        parent[b] = a;
        height[b] = height[a] + 1;
    }

    cin >> m;

    for(int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        cout << find(a, b) << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    proc();
    return 0;
}
