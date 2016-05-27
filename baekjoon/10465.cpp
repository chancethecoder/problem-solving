#include <iostream>
#include <cstdio>
#include <cstring>
#define min(a,b) ((a)<(b)?(a):(b))

using namespace std;
const int MAX_C = 100000;
int K;
int cnt[26];
char str[MAX_C + 1];
char tmp[MAX_C + 1];

void proc()
{
    cin >> K;

    scanf("%s", str);

    strcpy(tmp, str);

    for(int i = 0; i < K; ++i)
        ++cnt[str[i] - 'a'];

    for(int i = K; str[i] != '\0'; ++i)
    {
        int max_cnt = 0;
        int max_val = 0;

        for(int j = 0; j < 26; ++j)
        {
            if(max_val < cnt[j])
            {
                max_cnt = j + 1;
                max_val = cnt[j];
            }
        }

        str[i] = (str[i] - 'a' + max_cnt) % 26 + 'a';

        --cnt[tmp[i - K] - 'a'];
        ++cnt[tmp[i] - 'a'];
    }

    printf("%s\n", str);
}

int main()
{
    proc();
    return 0;
}
