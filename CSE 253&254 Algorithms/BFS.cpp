#include<bits/stdc++.h>
using namespace std;

vector<int>_vec[100];
queue<int>Q;

int n,e,i,j,u,v,level[101],state[101],s,d;

int main()
{
    cin>>n>>e;
    for(i=1; i<=e; i++)
    {
        cin>>u>>v;
        _vec[u].push_back(v);
        _vec[v].push_back(u);
    }
    for(i=1; i<=n; i++)
    {
        cout<<i<<"-->";
        for(auto v:_vec[i])
            cout<<v<<' ';
        cout<<endl;
    }
    cout<<"Enter the source node no.";
    cin>>s;
    level[s]=0;
    state[s]=1;
    Q.push(s);

    while(!Q.empty())
    {
        u=Q.front();
        Q.pop();
        for(auto v:_vec[u])
        {
            if(!state[v])
            {
                level[v]=level[u]+1;
                Q.push(v);
                state[v]=1;
            }
        }
    }
    cout<<"Enter the destination node no :";
    cin>>d;
    cout<<level[d]<<endl;
}
