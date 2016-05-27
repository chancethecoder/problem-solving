#include<stdio.h>

int cnt[105][105], que[100010][2];
int front, rear, n, m, p;
char map[105][105];

void enq(int a,int b);

int main(void)
{
    int i, j;

    scanf("%d %d",&n,&m);

    for(i=0;i<n;i++)
    {
        getchar(); scanf("%s", map[i]);
    }

    enq(0,0);

    return 0;
}

void enq(int a, int b)
{
    cnt[a][b] = 1;
    que[0][0] = a;
    que[0][1] = b;
    rear++;

    while(front < rear)
    {
        int na = que[front][0];
        int nb = que[front][1];
        front++;

        if(na - 1 >= 0 && cnt[na - 1][nb] == 0 && map[na - 1][nb] == '1')
        {
            que[rear][0] = na - 1;
            que[rear][1] = nb;
            cnt[na - 1][nb] = cnt[na][nb] + 1;
            rear++;
        }

        if(nb - 1 >= 0 && cnt[na][nb - 1] == 0 && map[na][nb - 1] == '1')
        {
            que[rear][0] = na;
            que[rear][1] = nb - 1;
            cnt[na][nb - 1] = cnt[na][nb] + 1;
            rear++;
        }

        if(na + 1 < n && cnt[na + 1][nb] == 0 && map[na + 1][nb] == '1')
        {
            que[rear][0] = na + 1;
            que[rear][1] = nb;
            cnt[na + 1][nb] = cnt[na][nb] + 1;
            rear++;
        }

        if(nb + 1 < m && cnt[na][nb + 1] == 0 && map[na][nb + 1] == '1')
        {
            que[rear][0] = na;
            que[rear][1] = nb + 1;
            cnt[na][nb + 1] = cnt[na][nb] + 1;
            rear++;
        }
    }

    printf("%d\n", cnt[n - 1][m - 1]);
}

/*
void enq(int a,int b)
{
    int i;
    cnt[a][b]++;
    front++;
    p++;

    if(a-1>=0 && cnt[a-1][b]==0 && map[a-1][b] == '1')
    {
        rear++;
        que[rear][0]=a-1;
        que[rear][1]=b;
        if(a-1==n-1&&b==m-1 && !cnt[a-1][b])
            printf("%d\n",p);
    }
    if(b-1>=0&&cnt[a][b-1]==0&&map[a][b-1]=='1')
    {
        rear++;
        que[rear][0]=a;
        que[rear][1]=b-1;
        if(a==n-1&&b-1==m-1 && !cnt[a][b-1])
            printf("%d\n",p);
    }
    if(a+1<=n-1&&cnt[a+1][b]==0&&map[a+1][b]=='1')
    {
        rear++;
        que[rear][0]=a+1;
        que[rear][1]=b;
        if(a+1==n-1&&b==m-1 && !cnt[a+1][b])
            printf("%d\n",p);
    }
    if(b+1<=m-1&&cnt[a][b+1]==0&&map[a][b+1]=='1')
    {
        rear++;
        que[rear][0]=a;
        que[rear][1]=b+1;
        if(a==n-1&&b+1==m-1 && !cnt[a][b+1])
            printf("%d\n",p);
    }

    for(i=front;i<=rear;i++)
        enq(que[i][0],que[i][1]);
}
*/
