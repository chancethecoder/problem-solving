#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
const int MAX_N = 20000;
int n;
string s[MAX_N];

bool cmp(string a, string b)
{
    return (a.size() == b.size() ? a < b : a.size() < b.size());
}

void proc()
{
    cin >> n;

    for(int i = 0; i < n; ++i)
        cin >> s[i];

    sort(s, s + n, cmp);

    for(int i = 0; i < n; ++i)
    {
        cout << s[i] << "\n";
        while(i < n - 1 && s[i] == s[i + 1]) ++i;
    }
}

int main()
{
    proc();
    return 0;
}
