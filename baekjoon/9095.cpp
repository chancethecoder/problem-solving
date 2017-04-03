#include <iostream>

using namespace std;

int main() {

    int tc; cin >> tc;

    while (tc--) {
        int n; cin >> n;
        int a[] = {0, 1, 2, 4, 7, 13, 24, 44, 81, 149, 274};
        cout << a[n] << endl;
    }

    return 0;
}
