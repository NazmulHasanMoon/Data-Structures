#include<bits/stdc++.h>
using namespace std;
#define sf scanf
#define pf printf
#define sz 100002
long long cnt[sz],f[sz];
int main()
{
    int n,a;
    sf("%d",&n);
    for(int i=0;i<n;i++)
        sf("%d",&a),cnt[a]++;
    f[1]=cnt[1];
    for(int i=2;i<sz;i++)
        f[i]=max(f[i-1],f[i-2]+i*cnt[i]);
    cout<<f[sz-1]<<endl;
    return 0;
}
