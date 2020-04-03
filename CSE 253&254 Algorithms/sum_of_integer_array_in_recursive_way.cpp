#include<bits/stdc++.h>
using namespace std;
int RSum(int a[],int n)
{
    if(n<0)
        return 0;
    else
        return RSum(a,n-1)+a[n];
}
int main()
{
    int a[4]={40,20,70,30};
    cout<<RSum(a,3);
    return 0;
}
