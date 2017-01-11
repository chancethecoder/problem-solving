#include <iostream>
#include <cstdio>
#include <map>

using namespace std;
typedef long long ll;

ll solve(int N, map<int, ll>& M) {
    if(N < 2) return (ll) N;
    if(M.find(N) != M.end()) return M[N];
    ll sum = solve(N - 1, M) + solve(N - 2, M);
    M.insert(make_pair(N, sum));
    return sum;
}

int main() {
    int N;
    map<int, ll> M;
    cin >> N;
    cout << solve(N, M) << endl;
}
