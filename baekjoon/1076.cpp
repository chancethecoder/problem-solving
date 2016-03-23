#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>

using namespace std;

const string str[] = {"black", "brown", "red", "orange", "yellow", "green",
                        "blue", "violet", "grey", "white"};

long long value(const string& S)
{
    for(int i = 0; i < 10; ++i)
        if(S == str[i]) return static_cast<long long>(i);
}

long long mult(const string& S)
{
    for(int i = 0; i < 10; ++i)
        if(S == str[i]) return (pow(10L, i));
}

void proc()
{
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    long long ans = 0;

    ans = (value(s1) * 10 + value(s2)) * mult(s3);

    cout << ans << endl;
}

int main()
{
    proc();
    return 0;
}
