#include<bits/stdc++.h>
using namespace std;
#define sz 500
int s[sz],e[sz],w[sz],k;
int main()
{
    int n,mx,c(0);
    mx=INT_MIN;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>s[i]>>e[i];
    for(int i=0;i<n;i++)
    {
        k=0;c=1;
        for(int j=i+1;j<n;j++)
        {
            if((e[i]<=s[j]&&s[i]>=e[j])||(s[i]>=e[j]&&s[j]<=e[i]))
                w[k++]=j;
        }
        for(int l=0;l<k-1;l++)
        {
            if((e[l]<=s[l+1]&&s[l]>=e[l+1])||(s[l]>=e[l+1]&&s[l+1]<=e[l]))
                c++;
        }
        mx=max(mx,c);
    }
    cout<<mx<<endl;
    return 0;
}
