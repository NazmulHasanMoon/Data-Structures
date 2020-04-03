#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
bool comp(pair<int,int>a,pair<int,int>b)
{
    if(((a.ss+0.0)/a.ff)>=((b.ss+0.0)/b.ff))
        return 1;
    else
        return 0;

}
int main()
{
    int m,n,x,y,s(0);
    cin>>m>>n;
    vector<pair<int,int>>v;
    vector<int>st;
    for(int i=0; i<n; i++)
    {
        cin>>x>>y;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end(),comp);
    vector<pair<int,int>>::iterator i;
    for(i=v.begin();i!=v.end();i++)
    {
        if(i->ff<m)
            s+=i->ss,m-=i->ff,st.push_back(i->ff);
    }
    cout<<s<<endl<<endl;
    vector<int>::iterator it;
    for(it=st.begin();it!=st.end();it++)
        cout<<*it<<' ';
    cout<<endl;
    return 0;
}
