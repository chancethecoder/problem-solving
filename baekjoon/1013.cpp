#include <iostream>
#include <cstdio>
#include <string>

using namespace std;
int length;
string str;

bool solve(string s)
{
    if(s.length() > length) return false;
    if(s == str) return true;

    if(solve(s + "100") || solve(s + "1"))
        return true;
    else if(solve(s + "01"))
        return true;

    return false;
}

void proc()
{
    cin >> str;
    length = str.length();
    cout << (solve("") ? "YES\n" : "NO\n");
}

int main()
{
    int tc;
    scanf("%d", &tc);
    getchar();
    while(tc--)
        proc();
    return 0;
}
