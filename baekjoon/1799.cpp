#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
const int MAX_N = 10;
int n;
int board[MAX_N][MAX_N];
bool diagonals[2][2 * MAX_N + 1];
vector<pair<int, int> > colored[2];

int solve(int y, int x, int idx, int color)
{
    if(idx == colored[color].size() - 1)
        return (!diagonals[0][n - (y - x)] && !diagonals[1][x + y]);
    int ret = 0;

    for(int i = idx + 1; i < colored[color].size(); ++i)
    {
        int ny = colored[color][i].first;
        int nx = colored[color][i].second;
        if(diagonals[0][n - (y - x)] || diagonals[1][x + y]) continue;

        diagonals[0][n - (y - x)] = diagonals[1][x + y] = true;
        int tmp = solve(ny, nx, i, color) + 1;
        if(ret < tmp) ret = tmp;
        diagonals[0][n - (y - x)] = diagonals[1][x + y] = false;
    }

    return ret;
}

void proc()
{
    cin >> n;

    for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j)
    {
        cin >> board[i][j];
        if(board[i][j] == 1)
            colored[(i + j) % 2].push_back(make_pair(i, j));
    }

    int ans = 0;

    for(int i = 0; i < 2; ++i)
        if(!colored[i].empty())
            ans += solve(colored[i][0].first, colored[i][0].second, 0, i);

    cout << ans << endl;
}

int main()
{
    proc();
    return 0;
}
