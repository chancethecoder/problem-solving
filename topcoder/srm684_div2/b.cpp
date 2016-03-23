#include <iostream>
#include <string>

using namespace std;
const int MOD = 1000000007;
int cache[100001];

struct DivFreed2{

    int count(int n, int k)
    {
        for(int i = 1; i <= k; ++i)
            cache[i] = i;

        for(int i = 2; i <= n; ++i)
        {
            for(int j = 2; j <= k; ++j)
            {
                cache[j] = (cache[j - 1] + (j + 1)) % MOD;
            }
        }

        int ans = 0;

        for(int i = 1; i <= k; ++i)
            ans += cache[i];

        return ans;
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    DivFreed2 solver;
    cout << solver.count(n, k) << endl;
}
