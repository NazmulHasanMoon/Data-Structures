#include<bits/stdc++.h>
using namespace std;
int LB(int a[],int n,int key)
{
    int b=0,e=n,m;
    while(b<=e)
    {
        m=(b+e)/2;
        if(a[m]==key)
            e=m-1;
        else if(a[m]>key)
            e=m-1;
        else if(a[m]<key)
            b=m+1;
    }
    return b;
}
/*This function also produce correct answer
int LB(int a[], int n,int key) {
    int l = 0;
    int h = n; // Not n - 1
    while (l < h) {
        int mid = (l + h) / 2;
        if (key > a[mid]) {
            l = mid + 1;
        } else {
            h = mid;
        }
    }
    return l;
}*/
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int x;
    cin>>x;
    cout<<"Lower bound: "<<LB(a,n,x);
    ///x=lower_bound(a,a+n,x)-a;
    return 0;
}
