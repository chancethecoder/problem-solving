#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX_N = 100;
const int MAX_M = 15;

typedef struct{
    int score[MAX_M + 2];
    bool solved[MAX_M + 2];
}data;

typedef struct{
    int num, solved, total_score;
}rank;

int n, m, q;
data team[MAX_N + 2];
rank ranked[MAX_N + 2];

bool cmp(rank a, rank b)
{
    if(a.solved == b.solved)
    {
        if(a.total_score == b.total_score)
        {
            return a.num < b.num;
        }
        return a.total_score < b.total_score;
    }
    return a.solved > b.solved;
}

void proc()
{
    cin >> n >> m >> q;

    int spend, team_num, pb_num;
    char res[5];
    for(int i = 0; i < q; ++i)
    {
        scanf("%d %d %d %s", &spend, &team_num, &pb_num, res);
        if(team[team_num].solved[pb_num]) continue;

        if(res[0] == 'A')
        {
            team[team_num].solved[pb_num] = true;
            team[team_num].score[pb_num] += spend;
        }
        else
        {
            team[team_num].score[pb_num] += 20;
        }
    }

    for(int i = 1; i <= n; ++i)
    {
        ranked[i].num = i;
        for(int j = 1; j <= m; ++j)
        {
            if(team[i].solved[j])
            {
                ++ranked[i].solved;
                ranked[i].total_score += team[i].score[j];
            }
        }
    }

    sort(ranked + 1, ranked + n + 1, cmp);

    for(int i = 1; i <= n; ++i)
    {
        printf("%d %d %d\n", ranked[i].num, ranked[i].solved, ranked[i].total_score);
    }
}

int main()
{
    proc();
    return 0;
}
