#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define sz 200
int w[sz],v[sz];
int main()
{
    int k,n,x,y,mx(INT_MIN);
    cin>>k>>n;
    bool t=1;
    for(int i=0;i<n;i++)
        cin>>w[i]>>v[i];
    for(int i=0;i<n;i++)
    {
        x=y=0;
        t=1;
        for(int j=i;j<n&&w[i]<=k;j++)
        {
            x+=w[j];
            if(x<=k)
                y+=v[j];
            else{
                mx=max(mx,y);
                for(int l=i+1;l<j;l++)
                {
                    x-=w[l];
                    y-=v[l];
                    //cout<<y<<' '<<x<<"** ";
                    if(x<=k)
                    {
                        y+=v[j];
                        //cout<<y<<' ';
                        break;
                    }
                }
                //cout<<endl<<mx<<endl;
            }
        }
        mx=max(mx,y);
        //cout<<mx<<"*\n";
    }
    cout<<mx<<endl;
    return 0;
}
