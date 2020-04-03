#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define sz 200
int m,s(0);
vector<pair<int,int>>v;
bool comp(pair<int,int>a,pair<int,int>b)
{
    if(a.ss<=b.ss)
        return 1;
    else
        return 0;

}
//vector<pair<int,int>>::iterator it=v.begin();
void RAS(int k,int n)
{
    m=k+1;
    //cout<<m<<endl;
    //cout<<v[m].ff<<' '<<v[k].ss<<endl;
    while(m<=n&&v[m].ff<v[k].ss)
        m++;
    if(m<=n){
        s++;
        RAS(m,n);
    }
    else
        return;
}
int main()
{
    int n,x,y;
    cin>>n;
    v.push_back({0,0});
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end(),comp);///comp function overloading
    /*for(auto i:v)
    {
        cout<<i.ff<<' '<<i.ss<<endl;
    }*/
    //cout<<endl;
    RAS(0,n);
    cout<<s<<endl;
    return 0;
}
