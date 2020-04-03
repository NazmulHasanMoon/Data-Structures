#include<bits/stdc++.h>
using namespace std;
#define sf scanf
#define pf printf
#define ff first
#define ss second
#define sz 100
int m[sz][sz],s[sz][sz];
typedef long long ll;
void optimal_parens(int i,int j)
{
    if(i==j)
        pf("A%d",i);
    else
    {
        pf("(");
        optimal_parens(i,s[i][j]);
        optimal_parens(s[i][j]+1,j);
        pf(")");
    }
}
int MCM(int p[],int n)
{
    for(int l=2;l<=n;l++)
    {
        for(int i=1;i<=n-l+1;i++)
        {
            int j=i+l-1;
            m[i][j]=INT_MAX;
            for(int k=i;k<j;k++)
            {
                int q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<m[i][j]){
                m[i][j]=q;
                s[i][j]=k;
                }
            }
        }
    }
    return m[1][n];
}
int main()
{
    int n,p[sz];
    pf("Enter number of matrixs: ");
    sf("%d",&n);
    pf("Enter dimensions: ");
    for(int i=0;i<=n;i++)
        sf("%d",&p[i]);
    pf("Minimum number of multiplication is : %d\n",MCM(p,n));
    optimal_parens(1,n);
    pf("\n");
    return 0;
}
