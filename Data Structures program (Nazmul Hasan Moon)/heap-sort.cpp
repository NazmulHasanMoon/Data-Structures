#include<bits/stdc++.h>
using namespace std;
#define sz 1000
int h[sz],c;
void heap(int *h,int j)
{
    while(j)
    {
        if(h[j]>h[(j-1)/2])
            swap(h[j],h[(j-1)/2]);
        j=(j-1)/2;
        c++;
    }
}
void heapsort(int *h,int n)
{
    for(int i=n-1;i>=0;i--)
    {
        for(int j=i;j>=0;j--)
            heap(h,j);

        swap(h[0],h[i]);
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>h[i];
    heapsort(h,n);
    for(int i=0;i<n;i++)
        cout<<h[i]<<((i<n-1)?' ':'\n');
    cout<<"C "<<c<<endl;
    return 0;
}
