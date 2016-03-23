#include <string>
#include <iostream>

using namespace std;

class Istr{
public:
    int count(string s, int k)
    {
        int cnt[26] = {0};

        int len = s.length();

        for(int i = 0; i < len; ++i)
            ++cnt[s[i]-'a'];

        for(int i = 0; i < k; ++i)
        {
            int mmax = cnt[0];
            int midx = 0;
            for(int j = 1; j < 26; ++j)
                if(cnt[j] > mmax)
                {
                    mmax = cnt[j];
                    midx = j;
                }
            --cnt[midx];
        }

        int ans = 0;

        for(int i = 0; i < 26; ++i)
            ans += cnt[i] * cnt[i];

        return ans;
    }
};

int main()
{
    string s;
    int k;
    cin >> s >> k;
    lstr solver;
    cout << solver.count(s, k) << endl;
}
