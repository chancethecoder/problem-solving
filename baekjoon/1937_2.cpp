#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define max(a,b) ((a)<(b)?(b):(a))

using namespace std;
const int MAX_N = 500;
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};
int n;
int ans;
int map[MAX_N][MAX_N];
int cache[MAX_N][MAX_N];
vector<pair<int, pair<int, int> > > list;

void proc()
{
    cin >> n;

    for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j)
    {
        scanf("%d", &map[i][j]);
        list.push_back(make_pair(map[i][j], make_pair(i, j)));
    }

    sort(list.begin(), list.end());

    for(int i = 0; i < list.size(); ++i)
    {
        int y = list[i].second.first;
        int x = list[i].second.second;

        for(int k = 0; k < 4; ++k)
        {
            int ny = y + dy[k];
            int nx = x + dx[k];

            if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;

            if(!cache[ny][nx] || (cache[ny][nx] && map[y][x] > map[ny][nx]))
                cache[y][x] = max(cache[y][x], cache[ny][nx] + 1);
        }

        ans = max(ans, cache[y][x]);
    }

    cout << ans << "\n";
}

int main()
{
    proc();
    return 0;
}
