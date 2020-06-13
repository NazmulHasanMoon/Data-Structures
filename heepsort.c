#include<stdio.h>
//int a[100];
void Min(int *arr,int i,int n)
{
    int left,right,min;
    left=2*i;
    right=i*2+1;
    if(left<=n&&arr[left]<arr[i])
        min=left;
    else
        min=i;
    if(right<=n&&arr[right]<arr[min])
        min=right;
    if(min!=i)
    {
        int temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
        Min(arr,min,n);
    }
}
void minheep(int *arr,int n)
{
    int i;
    for(i=n/2;i>=1;i--)
        Min(arr,i,n);
}
void heepsort(int *arr,int n)
{
    for(int i=n;i>=2;i--)
    {
        int temp=arr[i];
        arr[i]=arr[1];
        arr[1]=temp;
        Min(arr,1,i-1);
    }
}
int main()
{
    int n,val;
    scanf("%d",&n);
    int a[n+1];
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    minheep(a,n);
    heepsort(a,n);
    for(int i=1;i<=n;i++)
        printf("%d ",a[i]);
    return 0;
}
