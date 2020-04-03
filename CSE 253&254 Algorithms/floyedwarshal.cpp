//floyd warshal
#include<bits/stdc++.h>
using namespace std;
#define ss second
#define ff first
int par[101],r[101];
int g[101][101];
int main()
{
    int n,e,x,y,c;
    //freopen("input2.txt","r",stdin);
    cin>>n>>e;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j)
                g[i][j]=1e8;
        }
    }
    for(int i=1;i<=e;i++)
    {
        cin>>x>>y>>c;
        g[x][y]=c;

        //cout<<g[x][y]<<endl;
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
                    //cout<<g[i][j]<<' ';
            //cout<<endl<<endl;;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<g[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}
