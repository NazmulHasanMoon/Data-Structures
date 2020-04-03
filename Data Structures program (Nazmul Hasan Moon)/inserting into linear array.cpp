#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n+1];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int x,k,j=n-1;
    cin>>k;
    while(j>=k-1)
    {
        a[j+1]=a[j];
        j--;
    }
    cin>>x;
    a[k-1]=x;
    for(int i=0;i<=n;i++)
        cout<<a[i]<<' ';
    cout<<endl;
    return 0;
}
