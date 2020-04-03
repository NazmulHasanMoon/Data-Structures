#include<bits/stdc++.h>
using namespace std;
#define sz 10000
int a[sz];
int part(int a[],int start,int end)
{
    int pIndex=start,pivot=a[end];
    for(int i=start;i<end;i++)
    {
        if(a[i]<=pivot)
            swap(a[i],a[pIndex++]);//cout<<a[i]<<' '<<i<<endl;
    }
    swap(a[end],a[pIndex]);
    cout<<pIndex<<endl;
    return pIndex;
}
void quick(int a[],int start,int end)
{
    if(start<end)
    {
        int pIndex=part(a,start,end);
        quick(a,start,pIndex-1);
        quick(a,pIndex+1,end);
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    quick(a,0,n-1);
    for(int i=0;i<n;i++)
        cout<<a[i]<<' ';
    cout<<endl;
    return 0;
}
