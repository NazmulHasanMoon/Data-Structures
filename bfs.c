#include<stdio.h>
#include<stdlib.h>
#define sf scanf
#define pf printf
struct list
{
    int val;
    struct list *next;
};
typedef struct list linklist;
linklist *G[1000],*queue;
int vis[1000];
void push(linklist** head_ref,int adj)
{
    linklist *new_node=(linklist*)malloc(sizeof(linklist));
    linklist *temp=*head_ref;
    new_node->val=adj;
    new_node->next=NULL;
    if(*head_ref==NULL)
    {
        *head_ref=new_node;
        return;
    }
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=new_node;
}
void dequeue(linklist** head_ref)
{
    linklist *temp=*head_ref;
    *head_ref=temp->next;
    free(temp);
}
int main()
{
    int i,v,e,x,y,source,dest,front;
    sf("%d %d",&v,&e);
    for(i=1;i<=v;i++)
        G[i]=NULL;
    for(i=0;i<e;i++)
    {
        sf("%d %d",&x,&y);///undirected graph
        push(&G[x],y);
        push(&G[y],x);
    }
    sf("%d %d",&source,&dest);
    queue=NULL;
    push(&queue,source);
    vis[source]=1;
    while(queue!=NULL)
    {
        front=queue->val;
        dequeue(&queue);
        linklist *temp=G[front];
        while(temp!=NULL)
        {
           /// pf("%d!!!%d#\n",temp->val,front);
            if(!vis[temp->val])
                push(&queue,temp->val),vis[temp->val]=1;
            temp=temp->next;
        }
        pf("%d ",front);
    }
    pf("\n");
    return 0;
}
