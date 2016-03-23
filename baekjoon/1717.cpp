#include <iostream>
#include <cstdio>

using namespace std;
const int MAX_N = 1000000;
int n, m;
int parent[MAX_N + 1];
int rank[MAX_N + 1];

void init()
{
    for(int i = 1; i <= MAX_N; ++i)
        parent[i] = i;
}

int find(int p)
{
    if(parent[p] == p) return p;
    return parent[p] = find(parent[p]);
}

void merge(int p, int q)
{
    p = find(p);
    q = find(q);

    if(rank[p] < rank[q])
    {
        parent[p] = q;
    }
    else
    {
        parent[q] = p;
    }

    if(rank[p] == rank[q]) ++rank[p];
}

void proc()
{
    cin >> n >> m;

    init();

    for(int i = 0; i < m; ++i)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        if(a == 0)
            merge(b, c);
        else
            puts(find(b) == find(c) ? "YES" : "NO");
    }
}

int main()
{
    proc();
    return 0;
}
