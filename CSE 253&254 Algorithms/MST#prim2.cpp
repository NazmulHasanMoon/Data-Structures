#include<bits/stdc++.h>
using namespace std;
#define sz 100
vector<int>v[sz];
int p[sz],k[sz];
bool vis[sz];
map<int,int>vc[sz];
int main()
{
    int n,e,x,y,cost;
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        cin>>x>>y>>cost;
        vc[x][y]=cost;
        vc[y][x]=cost;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=1;i<n;i++)
        k[i]=INT_MAX;
    p[0]=-1;
    for(int i=0;i<n-1;i++)
    {
        int u,mn=INT_MAX;
        if(vis[i]==false&&k[i]<mn)
            mn=k[i],u=i;
        for(auto j:v[i])
        {
            if(vis[j]==false&&k[j]<mn)
                mn=k[j],u=j;
        }
        vis[u]=true;
        for(auto j: v[u])
        {
            if(!vis[j]&&k[j]>vc[u][j])
                k[j]=vc[u][j],p[j]=u;
        }
    }
    int s(0);
    for(int i=1;i<n;i++)
    {
        s+=vc[p[i]][i];
        cout<<p[i]<<'-'<<i<<' '<<vc[p[i]][i]<<endl;
    }
    cout<<"min cost = "<<s<<endl;
    return 0;
}
