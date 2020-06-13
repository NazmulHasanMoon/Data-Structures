#include<stdio.h>
#include<stdlib.h>
#define sf scanf
#define pf printf
struct link
{
    int d;
    struct link *left;
    struct link *right;
};
typedef struct link list;
void inorder(list *node)
{
    if(node)
    {
        inorder(node->left);
        pf("%d ",node->d);
        inorder(node->right);
    }
}
list * New(int v)
{
    list *temp=(list*)malloc(sizeof(list));
    temp->d=v;
    temp->left=temp->right=NULL;
    return temp;
}
list * insert(list *new_node,int v)
{
    if(new_node==NULL)
        return New(v);
    if(v<new_node->d)
        new_node->left=insert(new_node->left,v);
    else
        new_node->right=insert(new_node->right,v);
    return new_node;
}
int main()
{
    list *head=NULL;
    int n,root_v,v,i;
    sf("%d %d",&n,&root_v);
    head->d=root_v;
    head->left=NULL;
    head->right=NULL;
    for(i=0;i<n;i++)
        sf("%d",&v),insert(head,v);
    return 0;
}
