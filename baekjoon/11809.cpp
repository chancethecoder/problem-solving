#include <iostream>
#include <string>
using namespace std;

void print_to_number(const string& S)
{
    if(S.empty())
    {
        cout << "YODA\n";
        return;
    }

    int num = 0, idx = S.size() - 1;
    int radix = 1;

    while(idx >= 0)
    {
        num += (S[idx] - '0') * radix;
        radix *= 10;
        --idx;
    }

    cout << num << endl;
}

void solve(const string& A, const string& B)
{
    string AA(A), BB(B);
    int a_idx = A.size() - 1, b_idx = B.size() - 1;

    while(a_idx >= 0 && b_idx >= 0)
    {
        if(A[a_idx] < B[b_idx])
        {
            AA.erase(a_idx, 1);
        }
        else if(A[a_idx] > B[b_idx])
        {
            BB.erase(b_idx, 1);
        }

        --a_idx;
        --b_idx;
    }
    print_to_number(AA);
    print_to_number(BB);
}

void proc()
{
    string A, B;
    cin >> A >> B;
    solve(A, B);
}

int main()
{
    proc();
    return 0;
}
