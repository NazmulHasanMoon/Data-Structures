#include<stdio.h>
int main()
{
    int i,j,k,n,a[100],x,mid,start,end,A[100];
    scanf("%d\n",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                k=a[i];
                a[i]=a[j];
                a[j]=k;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        A[i]=a[i];
    }
    scanf("%d",&x);
    start=0;
    end=n-1;
    mid=(start+end)/2;
    while(start<=end)
    {
        if(x==A[mid])
        {
            printf("location = %d search value = %d\n",mid+1,x);
            break;
        }
        else if(x>A[mid])
        {
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
        mid=(start+end)/2;
    }
    return 0;
}
