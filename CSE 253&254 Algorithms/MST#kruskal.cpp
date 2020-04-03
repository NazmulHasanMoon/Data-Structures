#include<bits/stdc++.h>
using namespace std;
#define sz 100
int par[sz];
struct edge{
    int u,v,w;
    bool operator <(const edge &x)const
    {
        return w<x.w;
    }
};
vector<edge>vv;
int findset(int r)
{
    if(par[r]==r)
        return r;
    else
        return findset(par[r]);

}
int main()
{
    int n,e,s,c;
    s=c=0;
    cin>>n>>e;
    int x,y,z;
    for(int i=0;i<e;i++)
    {

        cin>>x>>y>>z;
        edge ed;
        ed.u=x;
        ed.v=y;
        ed.w=z;
        vv.push_back(ed);
    }
    for(int i=0;i<n;i++)
        par[i]=i;
    sort(vv.begin(),vv.end());
    for(int i=0;i<e;i++)
    {
        x=findset(vv[i].u);
        y=findset(vv[i].v);
        if(x!=y)
        {
            c++;
            s+=vv[i].w;
            par[y]=x;
            if(c==n-1)
                break;
        }
    }
    cout<<s<<endl;
    return 0;
}
