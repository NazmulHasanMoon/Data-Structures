#include<stdio.h>
#include<stdlib.h>
#define sf scanf
#define pf printf
int col[10000];
struct link
{
    int val;
    struct link *next;
};
typedef struct link list;
list *G[10000];
int cycle;
void push(list** head_ref,int adj)
{
    list *new_node=(list*)malloc(sizeof(list));
    new_node->val=adj;
    if(*head_ref==NULL)
    {
        new_node->next=NULL;
        *head_ref=new_node;
        return;
    }
    new_node->next=*head_ref;
    *head_ref=new_node;
}
void dfs(int u)
{
    col[u]=1;
    list *node=G[u];
    while(node!=NULL)
    {
        if(col[node->val]==1){cycle++;
        ////pf("%d#%d\n",u,node->val);
        }
        if(col[node->val]==0)
            dfs(node->val);
        node=node->next;
    }
    col[u]=2;
}
int main()
{
    int n,e,u,v,i;
    sf("%d %d",&n,&e);///n=node e=edge
    for(i=1;i<=n;i++)
        G[i]=NULL;
    for(i=0;i<e;i++){
        sf("%d %d",&u,&v);
        push(&G[u],v);
    }
    for(i=1;i<=n;i++)
    {
        if(!col[i])
            dfs(i);
    }
    pf("%d\n",cycle);
    return 0;
}
