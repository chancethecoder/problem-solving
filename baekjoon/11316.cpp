#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

typedef pair<int,int> pii;

int solve()
{
  int n; cin >> n;
  int a[10000];
  int ret = 0;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ret = max(a[i], ret);
  }

  int s = 3;
  set<pii> cur;

  for (int i = 0; i < n; i++) {
    if (a[i] == 3)
    cur.insert(pii(i, i));
    if (i > 0 && a[i] + a[i - 1] == 3)
    cur.insert(pii(i - 1, i));
  }
  if (i < n - 1 && a[i] + a[i + 1] == 3)
  cur.insert(pii(i, i + 1));

  if (cur.size() > 0)
  ret = max(ret, 3);

  for (int i = 1; i <= 24; i++) {
    set<pii> next;
    s *= 2;

    for (int i = 0; i < n; i++) {
      if (a[i] == s)
      next.insert(pii(i, i));
    }

    for (const auto &p : cur) {
      pii m(p.second + 1, 0);
      for (auto it = cur.lower_bound(m); it != cur.end() && it->first == m.first; ++it) {
        next.insert(pii(p.first, it->second));
      }
    }

    if (next.size() > 0)
    ret = max(ret, s);

    cur.swap(next);
  }

  return ret;
}

int main() {

  int tc; cin >> tc;

  for (int i = 0; i < tc; i++)
  cout << solve() << endl;

  return 0;
}
