#include<stdio.h>
#define sz 100
int queue[sz],j,_front;
void enqueue(int x)
{
    queue[j++]=x;
}
void dequeue(void)
{
    if(_front<j)
        _front++;
    else
        printf("Queue is Empty\n");
}
int front(void)
{
    ///printf("%d\n",queue[_front]);
   return queue[_front];
}
int isEmpty(void)
{
    if(_front==j)
        return 1;
    else
        return 0;
}
int main()
{
    printf("%d\n",isEmpty());
    enqueue(13);
    enqueue(front()*2);
    dequeue();
    printf("%d\n",isEmpty());
    printf("%d\n",front());
    return 0;
}
