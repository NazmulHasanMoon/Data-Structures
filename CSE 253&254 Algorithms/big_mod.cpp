#include<bits/stdc++.h>
using namespace std;
#define sf scanf
#define pf printf
typedef long long ll;
ll bigmod(ll a,ll b,ll m)
{
    if(b==0)
        return 1%m;
    if(b%2==0){
        int x=bigmod(a,b/2,m);
            return (x*x)%m;
    }
    else
        return ((a%m)*bigmod(a,b-1,m))%m;
}
int main()
{
    ll a,b,m;

    while(sf("%lld %lld %lld",&a,&b,&m)!=EOF){
    getchar();
    char c;
    sf("%c",&c);
    pf("%lld\n",bigmod(a,b,m));
    }
    return 0;
}

