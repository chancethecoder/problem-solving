#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 50;

int solve() {
    int arr[MAX_N];
    int N; cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    return arr[0] * arr[N - 1];
}

int main() {
    cout << solve() << endl;
}
