///***learn from: https://www.geeksforgeeks.org/linked-list-set-2-inserting-a-node/?ref=rp
#include<stdio.h>
#include<stdlib.h>
struct linklist
{
    int val;
    struct linklist *next;
};
typedef struct linklist Node;
void push(Node** head_ref,int v)
{
    Node *new_node=(Node*) malloc(sizeof(Node));
    new_node->val=v;
    new_node->next=(*head_ref);
    *head_ref=new_node;
}
void append(Node** head_ref,int v)
{
    Node *new_node=(Node*)malloc(sizeof(Node));
    Node *temp=*head_ref;
    new_node->val=v;
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
void insertAfter(Node *prev_node,int v)
{
    Node *new_node=(Node*)malloc(sizeof(Node));
    if(prev_node==NULL)
    {
        printf("Prev Node cann't be null\n");
        return;
    }
    new_node->val=v;
    new_node->next=prev_node->next;
    prev_node->next=new_node;
}
void print(Node *temp)
{
    if(temp!=NULL)
    {
        printf("%d ",temp->val);
        print(temp->next);
    }
}
void delete(Node** head_ref,int v)
{
    Node *temp=*head_ref,*prev;
    if(temp!=NULL&&temp->val==v)
    {
        *head_ref=temp->next;
        free(temp);
        return;
    }
    while(temp!=NULL&&temp->val!=v){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL)
        return;
    prev->next=temp->next;
    free(temp);
}
int main()
{
    Node *head=NULL;
    ///insert value in end of the linklist
    append(&head,5);
    ///insert in fornt of the linklist
    push(&head,3);
    append(&head,9);
    append(&head,4);///now list will be 3,5,9,4
    ///insert in a point that may be middile or 2nd element of linklist
    Node *temp=head->next->next;
    insertAfter(temp,6);///now list will be 3,5,9,6,4
    append(&head,9);
    append(&head,4);
    append(&head,12);
    append(&head,11);
    print(head);
    printf("\n");
    delete(&head,4);
    //printf("Hello\n");
    print(head);
    return 0;
}
