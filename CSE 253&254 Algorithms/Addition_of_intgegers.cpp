#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    int c=0;
    deque<int>x,y,s;
    while(a!=0)
    {
        x.push_front(a%2);
        a/=2;
    }
    while(b!=0)
    {
        y.push_front(b%2);
        b/=2;
    }
    int z(y.size()),w(x.size());
    if(z<w)
    {
        int d=w-z;
        while(d--)
            y.push_front(0);
    }
    else if(z>w)
    {
        int d=z-w;
        while(d--)
            x.push_front(0);
    }
    int n=max(z,w);
    for(int i=n-1;i>=0;i--)
    {
        int d=(x[i]+y[i]+c)/2;
        s.push_front(x[i]+y[i]+c-(2*d));
        c=d;
    }
    if(c==1)
        s.push_front(c);
    for(auto i:s)
        cout<<i;
    return 0;
}
