#include <iostream>
#include <cstdio>
#include <string>

using namespace std;
const int MAX_L = 1000000;
int idx;
char ans[MAX_L];
string str, bomb;


void proc()
{
    cin >> str >> bomb;

    for(int i = 0; i < str.size(); ++i)
    {
        ans[idx++] = str[i];

        int j = bomb.size() - 1;
        int k = 0;
        while(j >= 0 && ans[idx - k - 1] == bomb[j])
        {
            ++k, --j;
        }

        if(j == -1)
            idx -= bomb.size();
    }

    ans[idx] = '\0';

    cout << (idx ? ans : "FRULA") << "\n";
}

int main()
{
    proc();
    return 0;
}
