#include<bits/stdc++.h>
using namespace std;
#define sf scanf
#define pf printf
int main()
{
    freopen("E_LR.txt","r",stdin);
    freopen("E_LR_O.txt","w",stdout);
    string s,st,beta,alpha;
    cin>>s;
    char c=s[0];
    int x=s.size();
    alpha.push_back(c);
    beta.push_back(c);
    alpha+="`->";
    beta+="->";
    bool t=false;
    for(int i=3;i<x;i++)
    {
        if(s[i]==c)
        {
            i++;
            t=true;
            while(s[i]!='|'&&i<x)
            {
                alpha.push_back(s[i]);
                i++;
            }
            alpha.push_back(c);
            alpha.push_back('`');
            alpha.push_back('|');
        }
        else
        {
            while(s[i]!='|'&&i<x)
            {
                beta.push_back(s[i]);
                i++;
            }
            beta.push_back(c);
            beta+="`|";
        }
    }
    if(!t)
        cout<<"This is not valid a left recursive grammer\n";
    else
    {
        int z=beta.size()-1;
        for(int i=0;i<z;i++)
            cout<<beta[i];
        cout<<"\n";
        alpha+="NULL";
        for(auto i:alpha)
            cout<<i;
        cout<<endl;
    }
    return 0;
}
