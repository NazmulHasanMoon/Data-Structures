#include<bits/stdc++.h>
using namespace std;
int n;
template<class T>
void merge(T *x,int min,int mid,int max)
{
    T *y;
    y=new T[max+1];
    int i,j,k,m;
    cout<<min<<' '<<mid<<' '<<max<<endl;
    m=mid+1;
    for(i=j=min;j<=mid&&m<=max;i++)
    {
        if(*(x+j)<=*(x+m))
        {
            *(y+i)=*(x+j);
            j++;
        }
        else
        {
            *(y+i)=*(x+m),m++;
        }
    }
    if(j>mid)
    {
        for(k=m;k<=max;k++){
            *(y+i)=*(x+k),i++;
        }
    }
    else
    {
        for(k=j;k<=mid;k++){
            *(y+i)=*(x+k),i++;
        }
    }
    for(k=min;k<=max;k++)
        *(x+k)=*(y+k);//cout<<*(x+k)<<' ';
    //cout<<endl;
   delete y;
}
template<class T>
void sort1(T *x,int min,int max)
{
    int mid;
    if(min<max){
        mid=(min+max)/2;
        sort1(x,min,mid);

        sort1(x,mid+1,max);
        //cout<<min<<' '<<mid<<' '<<max<<endl;
        merge(x,min,mid,max);
    }
    else
        return ;

}
int main()
{
    cin>>n;
    int *x;
    x=new int[n];
    for(int i=0;i<n;i++)
        cin>>*(x+i);
    sort1(x,0,n-1);
    for(int i=0;i<n-1;i++)
        printf("%d ",*(x+i));
    cout<<*(x+(n-1))<<endl;
    delete x;
    return 0;
}
