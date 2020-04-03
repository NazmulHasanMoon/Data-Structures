#include<bits/stdc++.h>
using namespace std;
struct bst
{
    int info;
    struct bst *left,*right;
};
typedef struct bst tree;
tree *root=NULL;
void Insert(tree *r,tree *n)
{
    if(r->info>=n->info)
    {
        if(r->left==NULL)
            r->left=n;
        else
            Insert(r->left,n);
    }
    else if(r->info<n->info)
    {
        if(r->right==NULL)
            r->right=n;
        else
            Insert(r->right,n);
    }
}
tree *findmax(tree *x)
{
    while(x->right!=NULL)
        x=x->right;
    return x;
}
tree *Delete(tree *r,int d)
{
    if(r==NULL)
        cout<<"No such element exit\n";
    else if(r->info>d)
        r->right=Delete(r->right,d);
    else if(r->info<d)
        r->left=Delete(r->left,d);
    else
    {
        tree *temp;
        if(r->left&&r->right)
        {
            temp=findmax(r->left);
            r->info=temp->info;
            r->left=Delete(r->left,r->info);
        }
        else
        {
            temp=r;
            if(r->left==NULL)
                r=r->right;
            else if(r->right==NULL)
                r=r->left;
            free(temp);
        }
    }
    return r;
}
int main()
{
    tree *n;
    int x;
    while(cin>>x)
    {
        if(x==1)
        {
            int d;
            cin>>d;
            n=(tree*)malloc(sizeof(tree));
            n->info=d;
            n->left=n->right=NULL;
            if(root==NULL)
                root=n;
            else
                Insert(root,n);
        }
        else if(x==2)
        {
            int d;
            cin>>d;
            root=Delete(root,d);
        }
    }
    return 0;
}
