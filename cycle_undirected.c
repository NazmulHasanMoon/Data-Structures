#include<stdio.h>
#include<stdlib.h>
#define sf scanf
#define pf printf
struct link{
    int val;
    struct link *next;
};
typedef struct link list;
list *G[1000];
int vis[1000],par[1000],cycle;
void dfs(int u,int p)
{
    vis[u]=1;
    par[u]=p;
    list *node=G[u];
    while(node!=NULL)
    {
        if(node->val==p)
            return;
        if(!vis[node->val])
            par[node->val]=u,dfs(node->val,u);
        else if(par[node->val]!=u){
            cycle++;
            ///pf("%d#%d!!%d@%d\n",u,node->val,par[node->val],p);
            return;
        }
        node=node->next;
    }
}
void push(list ** head_ref,int adj)
{
    list *new_node=(list*)malloc(sizeof(list));
    new_node->val=adj;
    if(*head_ref==NULL)
    {

        new_node->next=*head_ref;
        *head_ref=new_node;
        return;
    }
    new_node->next=*head_ref;
    *head_ref=new_node;
}
int main()
{
    int n,e,i,u,v;
    sf("%d %d",&n,&e);
    for(i=1;i<=n;i++)
        G[i]=NULL;
    for(i=0;i<e;i++)
    {
        sf("%d %d",&u,&v);
        push(&G[u],v);
        push(&G[v],u);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i])
            dfs(i,-1);
    }
    pf("%d\n",cycle);
    return 0;
}
