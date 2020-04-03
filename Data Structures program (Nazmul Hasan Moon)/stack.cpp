#include<stdio.h>
#define sz 10000
#define sf scanf
#define pf printf
int stack[sz],j;
void push(int x)
{
    if(j+1<sz)
        stack[j++]=x;
    else
        pf("OverFlow\n");

}
void pop()
{
    if(j)
        j--;
    else
        pf("Under Flow");
}
int top()
{
    return stack[j-1];
}
bool isEmpty()
{
    return j==0;
}
int main()
{
    push(10);
    push(2);
    pop();
    push(top()*5+1);
    pf("%d\n",isEmpty());
    pf("%d\n",top());
    return 0;
}
