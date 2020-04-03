#include<bits/stdc++.h>
using namespace std;
void q(int a[],int n,int beg,int end,int *loc)
{
    int left=beg,right=end;
    *loc=beg;
step2:
    while(a[*loc]<=a[right]&&*loc!=right)
        right--;
    if(*loc==right)
        return;
    else if(a[*loc]>a[right])
        swap(a[*loc],a[right]),*loc=right;
    goto step3;
step3:
    while(a[left]<=a[*loc]&&left!=*loc)
        left++;
    if(*loc==left)
        return;
    else if(a[left]>a[*loc])
        swap(a[left],a[*loc]),*loc=left;
    goto step2;
}
void quick(int a[],int n)
{
    int top=-1;
    int lower[n],upper[n];
    if(n>0)
    {
        top++;
        lower[top]=0,upper[top]=n-1;
    }
    while(top!=-1)
    {
        int beg=lower[top],end=upper[top];top--;
        int loc;
        q(a,n,beg,end,&loc);
        if(beg<loc-1)
        {
            top++;
            lower[top]=beg,upper[top]=loc-1;
        }
        else if(loc+1<end)
        {
            top++;
            lower[top]=loc+1,upper[top]=end;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    quick(a,n);
    for(int i=0; i<n; i++)
        cout<<a[i]<<' ';
    return 0;
}
