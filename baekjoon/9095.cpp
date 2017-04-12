#include <iostream>

using namespace std;

int solve(int n) {
  if(n < 0) return 0;
  if(n == 0) return 1;
  return solve(n - 1) + solve(n - 2) + solve(n - 3);
}

int main() {

    int tc; cin >> tc;

    while (tc--) {
        int n; cin >> n;
        cout << solve(n) << endl;
    }

    return 0;
}
