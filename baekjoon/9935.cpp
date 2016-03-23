#include <iostream>
#include <cstdio>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;
string str;
string bomb;
stack<char> s;

void check()
{
    stack<char> tmp;
    int idx = bomb.size() - 1;

    while(idx >= 0 && s.top() == bomb[idx])
    {
        tmp.push(s.top());
        s.pop();
        --idx;
    }

    if(idx == -1) return;

    while(!tmp.empty())
    {
        s.push(tmp.top());
        tmp.pop();
    }
}

void proc()
{
    cin >> str >> bomb;

    for(int i = 0; i < str.size(); ++i)
    {
        s.push(str[i]);

        if(str[i] == bomb[bomb.size() - 1])
            check();
    }

    if(s.empty())
    {
        cout << "FRULA\n";
    }
    else
    {
        string ans;
        while(!s.empty())
        {
            ans += s.top();
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        cout << ans << "\n";
    }
}

int main()
{
    proc();
    return 0;
}
