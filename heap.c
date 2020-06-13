#include<stdio.h>
#define pf printf
#define sf scanf
int size=0;
int arr[100];
void Maxheepify(int *Arr,int i,int n)
{
    int left=i*2;
    int right=i*2+1;
    int large;
    if(left<=n&&Arr[i]<Arr[left])
        large=left;
    else
        large=i;
    if(right<=n&&Arr[right]>Arr[large])
        large=right;
    if(large!=i)
    {
        int temp=Arr[i];
        Arr[i]=Arr[large];
        Arr[large]=temp;
        Maxheepify(Arr,large,n);
    }
}
void buildMaxheep(int* Arr,int n)
{
    int i;
    for(i=n/2;i>=1;i--)
        Maxheepify(Arr,i,n);
}
int main()
{
    int n,key,i;
    sf("%d",&n);
    for(i=1;i<=n;i++)
        sf("%d",&arr[i]);///append(&head,key);
    buildMaxheep(arr,n);
    for(int i=1;i<=n;i++)
        printf("%d ",a[i]);
    return 0;
}
