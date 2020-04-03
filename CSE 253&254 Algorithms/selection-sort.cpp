#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    for(int i=0; i<n-1; i++)
    {
        int min=a[i];
        int loc=i;
        for(int j=i+1; j<n; j++)
        {
            if(min>a[j])
                min=a[j],loc=j;
        }
        swap(a[i],a[loc]);
    ///cout<<a[i]<<' '<<a[loc]<<endl;
    }
    for(int i=0; i<n; i++)
        cout<<a[i]<<' ';
    cout<<endl;
    return 0;
}
