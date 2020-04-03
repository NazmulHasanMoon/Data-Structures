#include<bits/stdc++.h>
using namespace std;
int UB(int a[],int n,int k)
{
    int b=0,e=n;
    while(b<e)
    {
        int mid=(b+e)/2;
        if(k>=a[b])
            b=b+1;
        else
            e=mid;
    }
    return b;
}
int main()
{
    int n;
    cin>>n;
    int a[n],k;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cin>>k;
    cout<<UB(a,n,k);
    //upper_bound(a,a+n,k)-a;
    return 0;
}
