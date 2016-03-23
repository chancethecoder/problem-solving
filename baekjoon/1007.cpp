#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;
const int MAX_N = 20;
const double INF = 1000000000.0;
int n;
int x[MAX_N];
int y[MAX_N];
int x_sum, y_sum;
bool added[MAX_N];

double dist(int x, int y)
{
    return sqrt(1.0 * x * x + 1.0 * y * y);
}

double solve(int _x, int _y, int smallest, int cnt)
{
    if(cnt == n / 2)
        return dist(x_sum - 2 * _x, y_sum - 2 * _y);

    double ret = INF;
    double tmp;
    for(int i = smallest + 1; i < n; ++i)
    {
        if(added[i]) continue;
        added[i] = true;
        tmp = solve(_x + x[i], _y + y[i], i, cnt + 1);
        added[i] = false;
        if(ret > tmp) ret = tmp;
    }

    return ret;
}

void proc()
{
    x_sum = y_sum = 0;
    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        cin >> x[i] >> y[i];
        x_sum += x[i];
        y_sum += y[i];
    }

    printf("%.6lf\n", solve(0, 0, -1, 0));
}

int main()
{
    int tc;
    for(scanf("%d", &tc); tc--; )
        proc();
    return 0;
}
