#include<bits/stdc++.h>
using namespace std;
#define sz 102
vector<int>vc[sz];
int par[sz],lvl[sz],r[sz],j(1);
bool vis[sz];
void path(int f,int s)
{
    if(f==s)
        return;
    path(par[f],s);
    cout<<par[f]<<' '<<f<<endl;
}
int main()
{
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        vc[u].push_back(v);
        vc[v].push_back(u);
    }
    int s,f;
    cin>>s>>f;
    vis[s]=1;
    lvl[s]=0;
    par[s]=s;
    queue<int>q;
    q.push(s);
    bool t=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vector<int>::iterator it;
        for(it=vc[u].begin();it!=vc[u].end();it++)
        {
            if(!vis[*it])
            {
                lvl[*it]=lvl[u]+1;
                q.push(*it);
                vis[*it]=1;
                //cout<<lvl[*it]<<' ';
                par[*it]=u;
            }
        }
        if(t)
            break;
    }
    path(f,s);
   /* r[0]=f;
    //cout<<r[0]<<' '<<endl;
    while(par[f]!=f)
    {
        r[j++]=par[f];
        f=par[f];
    }
    cout<<"Sortest path: ";
    for(int i=j-1;i>=0;i--)
        cout<<r[i]<<' ';*/
    cout<<endl<<"Distance from root = "<<lvl[f]<<endl;
    return 0;
}
