#include<stdio.h>
#include<stdlib.h>
#define sf scanf
#define pf printf
struct arr
{
    int a;
    struct arr *next;
};
typedef struct arr linklist;
linklist *G[1000];
int vis[1000];
void dfs(int u)
{
    vis[u]=1;
    linklist *temp=G[u];
    while(temp!=NULL)
    {
        if(!vis[temp->a])
            dfs(temp->a);
        temp=temp->next;
    }
}
void push(linklist** head,int u,int v)
{
    linklist *x;
    x=(linklist*)malloc(sizeof(linklist));
    x->a=v;
    if(*head==NULL)
    {
        x->next=NULL;
        *head=x;
        return;
    }
    x->next=*head;
    *head=x;
}
int main()
{
    int v,e,i,u1,u2,n;
    sf("%d %d",&v,&e);///v=vertex,e=edge
    for(i=1;i<=n;i++)
        G[i]=NULL;
    for(i=0;i<e;i++){
        sf("%d %d",&u1,&u2);
        push(&G[u1],u1,u2);
        push(&G[u2],u2,u1);
    }
    dfs(1);
    return 0;
}
