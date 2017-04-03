#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;

const int MAX_N = 30;
const int dy[] = { 1, -1, -2, -2, -1, 1, 2, 2 };
const int dx[] = { 2, 2, 1, -1, -2, -2, -1, 1 };

int n, m;
int map[MAX_N][MAX_N];

pii src, dst;

void solve()
{
}

int main() {

  cin >> m >> n;

  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      cin >> map[i][j];

      if(map[i][j] == 3) {
        src.first = i;
        src.second = j;
      }
      if(map[i][j] == 4) {
        dst.first = i;
        dst.second = j;
      }
    }
  }

  solve();

  return 0;
}
