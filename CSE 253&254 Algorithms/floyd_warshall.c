#include<stdio.h>
#include<stdlib.h>
#define sf scanf
#define pf printf
int arr[100][100],next[100][100];
void floyd(int n)
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(arr[i][j]>arr[i][k]+arr[k][j])
                {
                    arr[i][j]=arr[i][k]+arr[k][j];
                    next[i][j]=next[i][k];
                }
            }
        }
    }
}
void find_path(int s,int f)
{
    if(s==f)return;
    pf("%d ",next[s][f]);
    find_path(next[s][f],f);
}
int main()
{
    int n,e,u,v,w;
    sf("%d %d",&n,&e);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            arr[i][j]=1e9,next[i][j]=j;
    }
    for(int i=0;i<e;i++)
    {
        sf("%d %d %d",&u,&v,&w);
        arr[u][v]=w;
    }
    floyd(n);
    int s,f;
    sf("%d %d",&s,&f);
    find_path(s,f);
    return 0;
}
