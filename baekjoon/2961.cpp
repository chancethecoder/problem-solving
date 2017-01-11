#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;

const long long INF = 1000000007;
int N;
vector<pair<long long, long long> > food;

long long min(long long a, long long b) {
    return a < b ? a : b;
}

long long solve(int idx, long long mult, long long sum, bool added, bool contain) {

    if(idx > N - 1)
        return !contain ? INF : abs(mult - sum);

    if(added) {

        if(log(mult) + log(food[idx].first) > 10000000000.0) {
            return INF;
        }

        mult *= food[idx].first;
        sum += food[idx].second;
    }

    long long nextM = solve(idx + 1, mult, sum, true, contain | added);
    long long nextS = solve(idx + 1, mult, sum, false, contain | added);

    return min(nextM, nextS);
}

int main() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        long long a, b;
        cin >> a >> b;
        food.push_back(make_pair(a, b));
    }

    cout << min(solve(0, 1, 0, true, false), solve(0, 1, 0, false, false)) << endl;
}
