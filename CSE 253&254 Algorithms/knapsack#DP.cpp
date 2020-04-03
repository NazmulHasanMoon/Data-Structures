#include<bits/stdc++.h>
using namespace std;
#define sz 300
int m[sz][sz],w[sz],v[sz];
int main()
{
    int x,n,z;
    cin>>x>>n;
    for(int j=1;j<=n;j++)
        cin>>w[j]>>v[j];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=x;j++)
        {
            if(w[i]>j)
                m[i][j]=m[i-1][j];
            else
                m[i][j]=max(v[i]+m[i-1][j-w[i]],m[i-1][j]);
            //cout<<m[i][j]<<' ';
        }
        //cout<<endl;
    }
    cout<<m[n][x]<<endl;
    return 0;
}
