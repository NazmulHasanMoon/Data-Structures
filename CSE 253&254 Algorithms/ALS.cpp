#include<bits/stdc++.h>
using namespace std;
#define sz 100
int l[2][sz],p[2][sz],t1[sz],t2[sz],T[sz],T2[sz];
int main()
{
    int b[2],e[2];
    int s;
    cin>>s;
    for(int j=0; j<2; j++)
    {
        for(int i=0; i<s; i++)
            cin>>l[j][i];
    }
    cin>>b[0]>>b[1];
    cin>>e[0]>>e[1];
    T[0]=b[0]+l[0][0];
    T2[0]=b[1]+l[1][0];
    for(int i=1;i<s;i++)
        cin>>t1[i];
    for(int i=1;i<s;i++)
        cin>>t2[i];
    for(int i=1;i<s;i++)
    {
        T[i]=min(T[i-1]+l[0][i],T2[i-1]+t2[i]+l[0][i]);
        T2[i]=min(T2[i-1]+l[1][i],T[i-1]+t1[i]+l[1][i]);
    }
    cout<<min(T[s-1]+e[0],T2[s-1]+e[1]);
    return 0;
}
