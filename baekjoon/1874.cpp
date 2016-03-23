#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>

using namespace std;
const int MAX_N = 100000;
int n;
int arr[MAX_N];
vector<char> list;
stack<int> st;

void proc()
{
    cin >> n;

    for(int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    int idx = 0;
    int num = 1;
    int push_cnt = 0;

    while(idx < n)
    {
        if(push_cnt > n)
        {
            puts("NO");
            return;
        }

        if(!st.empty() && st.top() == arr[idx])
        {
            list.push_back('-');
            ++idx;
            st.pop();
        }
        else
        {
            list.push_back('+');
            st.push(num);
            ++num;
            ++push_cnt;
        }
    }
    
    for(int i = 0; i < list.size(); ++i)
        printf("%c\n", list[i]);
}

int main()
{
    proc();
    return 0;
}
