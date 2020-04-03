#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int x,k;
    cin>>k;
    x=a[k-1];
    for(int i=k-1;i<n-1;i++)
        a[i]=a[i+1];
    for(int i=0;i<n-1;i++)
        cout<<a[i]<<' ';
    cout<<endl;
    return 0;
}
