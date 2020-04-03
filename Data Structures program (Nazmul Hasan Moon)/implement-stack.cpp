#include<bits/stdc++.h>
using namespace std;
#define sz 5
int a[sz];
int top(0),rear(0);
void pop()
{
    if(top==-1)
        cout<<"Underflow\n";
    else
        --top;
}
void display()
{
    cout<<"\nThe final elements are: ";
    for(int i=top-1;i>=0;i--)
        cout<<a[i]<<' ';
    cout<<endl;
}
void push()
{
   if(top==sz)
        cout<<"Queue overflow\n";
   else
    cin>>a[top++];
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

