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
    if(node!=NULL)
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
list * search(list * node,int key)
{
    if(node==NULL||node->d==key)
        return node;
    if(key<node->d)
        return search(node->left,key);
    else
        return search(node->right,key);
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
list * MinRight(list* node)
{
    list *temp=node;
    while(temp!=NULL&&temp->left!=NULL)
        temp=temp->left;
    return temp;
}
list * Delete(list* node,int key)
{
    if(node==NULL)
        return node;
    if(key<node->d)
        node->left=Delete(node->left,key);
    else if(key>node->d)
        node->right=Delete(node->right,key);
    else
    {
        if(node->left==NULL)
        {
            list* temp=node->right;
            free(node);
            return temp;
        }
        else if(node->right==NULL)
        {
            list *temp=node->left;
            free(node);
            return temp;
        }
        node->d=MinRight(node->right)->d;
        node->right=Delete(node->right,node->d);
    }
     return node;
}
void preorder(list *head)
{
    if(head!=NULL)
    {
        pf("%d ",head->d);
        preorder(head->left);
        preorder(head->right);
    }
}
void postorder(list* head)
{
    if(head!=NULL)
    {
        preorder(head->left);
        preorder(head->right);
        pf("%d ",head->d);
    }
}
int main()
{
    list *head=NULL;
    int n,root_v,v,i;
    sf("%d %d",&n,&root_v);
    head=insert(head,root_v);
    for(i=1;i<n;i++)
        sf("%d",&v),insert(head,v);
    inorder(head);
    postorder(head);
    pf("\n");
    pf("%d\n",search(head,30)->d);
    Delete(head,30);
    inorder(head);
    pf("\n");
    preorder(head);
    pf("\n");
    postorder(head);
    return 0;
}

