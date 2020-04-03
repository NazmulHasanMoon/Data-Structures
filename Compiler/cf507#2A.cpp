#include<bits/stdc++.h>
using namespace std;
#define sf scanf
#define pf printf
#define sz 100000
#define ff first
#define ss second
#define pi acos(-1.0)
#define ll long long
#define all(a) a.begin(),a.end()
#define mem(a,v) memset((a), v, sizeof(a))
#define faster   ios_base::sync_with_stdio(0);cin.tie(0);

#define pb()   pushback()
int arr[200];
int main()
{
    faster
    int n,a,b,cost(0);
    cin>>n>>a>>b;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    bool t=true;
    for(int i=0,j=n-1;i<=j;i++,j--)
    {
        if(arr[i]!=arr[j])
        {
            if(arr[i]==2||arr[j]==2)
            {
                if(arr[i]==1||arr[j]==1)
                    cost+=b;
                else if(arr[i]==0||arr[j]==0)
                    cost+=a;
            }
            else
            {
                t=false;
                break;
            }
        }
        else if(arr[i]==arr[j]&&arr[i]==2){
            if(i==j)
                cost+=min(a,b);
            else
                cost+=2*(min(a,b));
        }
    }
    if(t)
        cout<<cost<<'\n';
    else
        cout<<"-1\n";
    return 0;
}

