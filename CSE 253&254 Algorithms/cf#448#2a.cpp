#include<bits/stdc++.h>
#include<cstring>
using namespace std;
#define pf printf
#define sf scanf
#define ss second
#define ff first
#define sz 362
int a[sz];

int main()
{
    int n,mn=INT_MAX;
    sf("%d",&n);
    for(int i=0;i<n;i++)
        sf("%d",&a[i]);
    for(int i=0;i<n;i++)
    {
        int s,x=a[i];
        s=x;
        for(int j=i+1;j<n;j++)
        {
            if(s+a[j]<360)
                s+=a[j];
            if(s>=180)
                break;
        }
        if(s<180)
        {
            for(int j=0;j<i;j++)
            {
                if(s+a[j]<360)
                    s+=a[j];
                if(s>=180)
                    break;
            }
        }
        mn=min(mn,s);
        if(mn==180)
        {
            cout<<"0\n";
            return 0;
        }
    }
    if(n>1)
    {
        mn=abs(mn-(360-mn));
        pf("%d\n",mn);
    }
    else
        pf("%d\n",a[0]);
    return 0;
}
