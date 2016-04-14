#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
static char _buffer[1024];
static int _currentIdx;
static int _lastIdx;

static inline int _read()
{
    if(_currentIdx == _lastIdx)
    {
        _lastIdx = fread(_buffer, sizeof(char), sizeof(_buffer), stdin);
        _currentIdx = 0;
    }

    return _buffer[_currentIdx++];
}

static inline int _readInt()
{
    int next = _read(), sum = 0, sign = 1;

    if(next == '-')
    {
        sign = -1;
        next = _read();
    }

    while(next > 32)
    {
        sum *= 10;
        sum += next - '0';
        next = _read();
    }

    return sign * sum;
}

const int MAX_N = 5000000;
int N, K;
int arr[MAX_N];

void proc()
{
    cin >> N >> K; _read();

    for(int i = 0; i < N; ++i)
        arr[i] = _readInt();

    nth_element(arr, arr + K - 1, arr + N);

    cout << arr[K - 1] << "\n";
}

int main()
{
    proc();
    return 0;
}
