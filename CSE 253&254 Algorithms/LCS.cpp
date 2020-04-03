#include<bits/stdc++.h>
using namespace std;
#define sf scanf
#define pf printf
#define sz 100
int a[sz][sz],b[sz][sz];
string x,y;
void LCS(int m,int n)
{
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(x[i-1]==y[j-1])
            {
                a[i][j]=a[i-1][j-1]+1;
                b[i][j]=1;
            }
            else if(a[i-1][j]>a[i][j-1])
            {
                a[i][j]=a[i-1][j];
                b[i][j]=2;
            }
            else
            {
                a[i][j]=a[i][j-1];
                b[i][j]=3;
            }
        }
    }
}
void print(int m,int n){
    if(m==0||n==0)
        return;
    if(b[m][n]==1)
    {
        print(m-1,n-1);
        pf("%c",x[m-1]);
    }
    else if(b[m][n]==2)
        print(m-1,n);
    else
        print(m,n-1);
}
int main()
{
    int n,m;

    cin>>x>>y;
    m=x.size();
    n=y.size();
    LCS(m,n);
    pf("\nLongest common subsequence :\n");
    print(m,n);
    pf("\n");
    return 0;
}
