///open linklist.c
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int val;
    struct Node *next;
};
typedef struct Node linklist;
void push(linklist** head_ref,int v)
{
    linklist *new_node=(linklist*)malloc(sizeof(linklist));
    new_node->val=v;
    new_node->next=*head_ref;
    *head_ref=new_node;
}
void insertAfter(linklist *prev,int v)
{
    linklist *new_node=(linklist*)malloc(sizeof(linklist));
    if(prev==NULL)
    {
        printf("Prev node cann't be NULL\n");
        return;
    }
    new_node->val=v;
    new_node->next=prev->next;
    prev->next=new_node;

}
void append(linklist ** head_ref,int x)
{
    linklist *new_node=(linklist*)malloc(sizeof(linklist));
    linklist *temp=*head_ref;
    new_node->val=x;
    new_node->next=NULL;
    if(*head_ref==NULL){
        *head_ref=new_node;
        return;
    }
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=new_node;
}
void Delete(linklist** head_ref,int x)
{
    linklist *temp=*head_ref,*prev;
    if(temp!=NULL&&temp->val==x)
    {
        *head_ref=temp->next;
        free(temp);
        return;
    }
    while(temp!=NULL&&temp->val!=x)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL)
       return;
    prev->next=temp->next;
    free(temp);
}
void deleteatpoint_n(linklist** head_ref,int i,int n)
{
    linklist *temp=*head_ref,*prev;
    if(temp!=NULL&&i==n)
    {
        *head_ref=temp->next;
        free(temp);
        return;
    }
    while(temp!=NULL&&i!=n)
    {
        prev=temp;
        temp=temp->next;
        i++;
    }
    if(temp==NULL)
       return;
    prev->next=temp->next;
    free(temp);
}
void print(linklist *head)
{
    if(head!=NULL)
    {
        printf("%d ",head->val);
        print(head->next);
    }
}
int main()
{
    linklist *head=NULL;
    append(&head,4);
    push(&head,6);
    insertAfter(head->next,9);
    Delete(&head,6);
    int n;
    push(&head,2);
    insertAfter(head->next,11);
    print(head);
    printf("\n");
    scanf("%d",&n);
    deleteatpoint_n(&head,0,n);
    print(head);
    return 0;
}
