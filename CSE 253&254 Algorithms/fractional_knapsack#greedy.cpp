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
    int m,n,x,y;
    double s(0);
    cin>>m>>n;
    vector<pair<int,int>>v;
    vector<int>st;
    for(int i=0; i<n; i++)
    {
        cin>>x>>y;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end(),comp);
    vector<pair<int,int>>::iterator it=v.begin();
    cout<<"\nThe selected items weight : ";
    for(it=v.begin();it!=v.end();it++)
    {
        if(it->ff<m){
            s+=it->ss,m-=it->ff;
            cout<<it->ff<<"="<<it->ss<<endl;
        }
        else if(m>0)
        {
            s+=(((it->ss+0.0)/it->ff)*m);
            cout<<endl<<"selected fractionl item's weight = "<<it->ff<<"="<<it->ss<<endl;
            m=0;
        }
    }
    cout<<s<<endl;
    return 0;
}

