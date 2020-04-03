#include<bits/stdc++.h>
using namespace std;
#define sz 1000
int a[sz];
void Merge(int a[],int mn,int mid,int mx)
{
    int temp[sz];
    int i,j,k,m;
    i=j=mn,m=mid+1;
    while(j<=mid&&m<=mx)
    {
        if(a[j]<=a[m])
            temp[i++]=a[j],j++;
        else
            temp[i++]=a[m],m++;
    }
    if(j>mid)
    {
        for(k=m;k<=mx;k++)
            temp[i++]=a[k];
    }
    else
    {
        for(k=j;k<=mid;k++)
            temp[i++]=a[k];
    }
    for(int l=mn;l<=mx;l++)
        a[l]=temp[l];
}
void sort1(int a[],int mn,int mx)
{
    int mid;
    if(mn<mx)
    {
        mid=(mn+mx)/2;
        sort1(a,mn,mid);
        sort1(a,mid+1,mx);
        Merge(a,mn,mid,mx);
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort1(a,0,n-1);
    for(int i=0;i<n;i++)
        cout<<a[i]<<' ';
    cout<<endl;
    return 0;
}
