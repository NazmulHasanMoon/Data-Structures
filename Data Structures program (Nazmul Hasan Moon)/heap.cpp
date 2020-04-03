#include<bits/stdc++.h>
using namespace std;
 #define sz 1000
 int heap[sz],i=-1;
 void Insert(int i)
 {
     while(i)
     {
         if(heap[i]>heap[(i-1)/2])
            swap(heap[i],heap[(i-1)/2]);
         i=(i-1)/2;
     }
 }
 void Delete(int j)
 {
     swap(heap[j],heap[0]),j--;
     int k=0;
     while(2*k+2<j)
     {
         if(heap[2*k+1]>heap[2*k+2])
            swap(heap[k],heap[2*k+1]),k=2*k+1;
         if(heap[2*k+1]<heap[2*k+2])
            swap(heap[k],heap[2*k+2]),k=2*k+2;
     }
 }
 void display(int i)
 {
     for(int j=0;j<=i;j++)
        cout<<heap[j]<<((j<i)?' ':'\n');
 }
 int main()
 {
     int x,d;
     while(cin>>x&&x!=0)
     {
         if(x==1)
         {
             cin>>d;
             heap[++i]=d;
             Insert(i);
         }
         else if(x==2)
         {
             if(i==-1)
                cout<<"Heap is empty\n";
             else
                Delete(i--);
         }
         else
         {
             if(i==-1)
                cout<<"Empty heap/tree\n";
             else
                display(i);
         }
     }
     return 0;
 }
