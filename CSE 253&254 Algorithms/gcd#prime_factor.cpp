#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,x;
    cin>>a>>b;
    x=1;
    for(int i=2;i<=a&&i<=b;i++)
    {
        if(a%i==0&&b%i==0)
            x=i;
    }
    cout<<x<<endl;
    return 0;
}
