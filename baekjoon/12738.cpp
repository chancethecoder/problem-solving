#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
const int MAX_N = 1000000;
int n;
int arr[MAX_N];
vector<int> vec;

void proc()
{
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    
    for(int i = 0; i < n; ++i)
    {
        int idx = lower_bound(vec.begin(), vec.end(), arr[i]) - vec.begin();
        if(vec.empty() || idx >= vec.size()) vec.push_back(arr[i]);
        else vec[idx] = vec[i];
    }
    
    printf("%d\n", vec.size());
}

int main()
{
    proc();
    return 0;
}
