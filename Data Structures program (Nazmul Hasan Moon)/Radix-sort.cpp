#include<bits/stdc++.h>
using namespace std;
#define sz 100
int a[10];
int main()
{
    int n,x[sz],y[sz],z[sz];
    cin>>n;
    int m,mx=-16255;
    for(int i=0; i<n; i++){
        cin>>x[i];
        if(mx<x[i])
            mx=x[i];
    }
    m=0;
    while(mx!=0)
    {
        mx/=10;
        m++;
    }
    int p=10;
    while(m--)
    {

        for(int i=0; i<n; i++)
        {
            y[i]=x[i]%p;
            y[i]=(y[i]*10)/p;
            a[y[i]]++;
        }
        for(int i=1; i<10; i++)
            a[i]+=a[i-1];
        for(int i=n-1; i>=0; i--)
        {
            int q=y[i];
            z[--a[q]]=x[i];
        }
        for(int i=0; i<n; i++)
            x[i]=z[i];//cout<<x[i]<<' ';
        for(int i=0;i<10;i++)
            a[i]=0;
        p*=10;
        //cout<<endl;
    }
    for(int i=0;i<n;i++)
        cout<<x[i]<<' ';
    cout<<endl;
    return 0;
}
