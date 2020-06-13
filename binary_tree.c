///hackerearth
#include<stdio.h>
#include<stdlib.h>
#define sf scanf
#define pf printf
struct link
{
    int data;
    struct link *left;
    struct link *right;
};
typedef struct link list;
int maxDepth(list* node)
{
    if (node==NULL)
        return 0;
    else
    {
        /* compute the depth of each subtree */
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);

        /* use the larger one */
        if (lDepth > rDepth)
            return(lDepth+1);
        else
            return(rDepth+1);
    }
}
list * newnode(int element)
{
    list * temp=(list* )malloc(sizeof(list));
    temp->data=element;
    temp->left=temp->right=NULL;
    return temp;
}
int main()
{
    list *head=NULL;
    int i,n,root,v,j;
    char ch[1000];
    sf("%d %d",&n,&root);
    head=newnode(root);
    n--;
    for(i=0; i<n; i++)
    {
        sf("%s",ch);
        sf("%d",&v);
        list *temp=head;
        for(j=0; ch[j+1]!='\0'; j++)
        {
            if(ch[j]=='L')
                temp=temp->left;
            else
                temp=temp->right;
        }
        if(ch[j]=='L')
            temp->left=newnode(v);
        else
            temp->right=newnode(v);
        ///pf("%d %d %d",head->data,head->left->data,temp->data);
    }
    pf("%d\n",maxDepth(head));
    return 0;
}
