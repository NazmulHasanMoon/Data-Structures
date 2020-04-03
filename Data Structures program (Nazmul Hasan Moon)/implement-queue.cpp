#include<bits/stdc++.h>
using namespace std;
#define sz 5
int a[sz];
int front(0),rear(0);
void pop()
{
    if(front==rear)
        cout<<"Underflow\n",front=rear=0;
    else
        rear++;
}
void display()
{
    if(front==0)
        cout<<"Queue is empty\n";
    else
    {
        cout<<"\nThe final elements are: ";
        for(int i=rear; i<front; i++)
            cout<<a[i]<<' ';
        cout<<endl;
    }
}
void push()
{
    if(front==sz)
        cout<<"Queue overflow\n";
    else
        cin>>a[front++];
}
int main()
{
    int n,x(1);
    while(x)
    {
        cin>>n;
        switch(n)
        {
        case 1:
            push(),x=1;
            break;
        case 2:
            pop(),x=1;
            break;
        case 3:
            display(),x=1;
            break;
        default:
            x=0;
            break;
        }
    }
    return 0;
}
