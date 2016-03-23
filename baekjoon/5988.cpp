#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

void proc()
{
    string s;
    cin >> s;
    puts((s[s.length() - 1] - 48) % 2 ? "odd" : "even");
}

int main()
{
    int n;
    for(scanf("%d", &n); n--; )
        proc();
    return 0;
}
