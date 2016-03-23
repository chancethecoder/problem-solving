#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <climits>
#include <bitset>
#include <stack>
#include <queue>
#include <vector>
#include <deque>
using namespace std;
int n, m;
char arr[102][102];
bool visited[102][102];

void BFS(){
    deque<short> y, x, l;
    y.push_back(0);
    x.push_back(0);
    l.push_back(1);

    while (!x.empty() && (x.front() != m-1 || y.front() != n-1)){

        if (!visited[y.front() - 1][x.front()]
            && y.front() > 0 && arr[y.front() - 1][x.front()] == '1'){

            visited[y.front() - 1][x.front()] = true;

            y.push_back(y.front() - 1);
            x.push_back(x.front());
            l.push_back(l.front() + 1);
            arr[y.front()][x.front()] = '0';
        }

        if (!visited[y.front() + 1][x.front()]
            && y.front() < n - 1 && arr[y.front() + 1][x.front()] == '1'){

            visited[y.front() + 1][x.front()] = true;

            y.push_back(y.front() + 1);
            x.push_back(x.front());
            l.push_back(l.front() + 1);
            arr[y.front()][x.front()] = '0';
        }

        if (!visited[y.front()][x.front() - 1] &&
            x.front() > 0 && arr[y.front()][x.front() - 1] == '1'){

            visited[y.front()][x.front() - 1] = true;

            y.push_back(y.front());
            x.push_back(x.front() - 1);
            l.push_back(l.front() + 1);
            arr[y.front()][x.front()] = '0';
        }

        if (!visited[y.front()][x.front() + 1] &&
            x.front() < m - 1 && arr[y.front()][x.front() + 1] == '1'){

            visited[y.front()][x.front() + 1] = true;

            y.push_back(y.front());
            x.push_back(x.front() + 1);
            l.push_back(l.front() + 1);
            arr[y.front()][x.front()] = '0';
        }

        y.pop_front();
        x.pop_front();
        l.pop_front();
    }

    if (!x.empty())
        cout << l.front() << "\n";
}

int main(){
    int i, j;
    string s;
    cin >> n >> m;

    for (i = 0; i < n; i++){
        cin >> s;
        for (j = 0; j < m; j++)
            arr[i][j] = s[j];
    }

    BFS();
    return 0;
}
