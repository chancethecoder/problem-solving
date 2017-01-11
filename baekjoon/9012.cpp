#include <iostream>
#include <cstdio>
#include <stack>
#include <string>

using namespace std;

const string solve() {
    string str; cin >> str;

    stack<char> s;
    int len = str.length();
    for(int i = 0; i < len; i++) {
        if(str[i] == '(') {
            s.push('(');
        }
        else {
            if(s.empty()) return "NO";
            char c = s.top(); s.pop();
        }
    }

    return s.empty() ? "YES" : "NO";
}

int main() {
    int tc; cin >> tc;

    for(int i = 0; i < tc; i++)
        cout << solve() << endl;
}
