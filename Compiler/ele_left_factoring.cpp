#include<bits/stdc++.h>
using namespace std;
#define sf scanf
#define pf printf
int main()
{
    freopen("E_LF.txt","r",stdin);
    freopen("E_LF_O.txt","w",stdout);
    vector<pair<int,int>>v;
    string s,st[100],beta,alpha,A;
    cin>>s;
    char c=s[0];
    int x=s.size();
    alpha.push_back(c);
    beta.push_back(c);
    beta+="`->";
    alpha+="->";
    bool t=false;
    int j,k,l;
    j=l=0;

    for(int i=3; i<x; i++)
    {
        k=0;
        while(s[i]!='|'&&i<x)
        {
            st[j].push_back(s[i]);
            i++;
            k++;
        }
        if(k==1)
            alpha+=st[j],alpha.push_back('|');
        else
            v.push_back({k,j}),l++;
        j++;

    }
    sort(v.begin(),v.end());
    for(int i=0; i<l; i++)
    {
        if(!t)
        {
            for(int x=i+1; x<l; x++)
            {
                int L=v[i].first;
                if(!t)
                {
                    for(int y=0; y<L; y++)
                    {
                        if(st[v[i].second][y]==st[v[x].second][y])
                            A.push_back(st[i][y]),t=true;
                        else
                            break;
                    }
                }
            }
        }
    }
    bool ck;
    alpha+=A;
    alpha.push_back(c);
    alpha.push_back('`');
    for(auto i: v)
    {
        ck=true;
        int L=i.first;
        for(int x=0; x<L; x++)
        {
            if(A[x]&&st[i.second][x]==A[x]&&ck)
                continue;
            else
            {
                ck=false;
                beta.push_back(st[i.second][x]);
            }
        }
        if(!ck)
            beta.push_back('|');
    }
    beta+="NULL";
    for(auto i:alpha)
        cout<<i;
    cout<<endl;
    for(auto i:beta)
        cout<<i;
    cout<<endl;
    return 0;
}

