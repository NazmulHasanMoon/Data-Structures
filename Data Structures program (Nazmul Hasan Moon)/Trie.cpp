#include<iostream>
#include<cstdio>
using namespace std;
struct node
{
    bool endmark;
    node *next[27];
    node()
    {
        endmark=false;
        for(int i=0;i<26;i++)
            next[i]=NULL;
    }
}*root;
void insert(char *str,int len)
{
    node *temp=root;
    for(int i=0;i<len;i++)
    {
        int id=str[i]-'a';
        if(temp->next[id]==NULL)
            temp->next[id]=new node();
        temp=temp->next[id];
    }
    temp->endmark=true;
}
bool search(char *str,int len)
{
    node *temp=root;
    for(int i=0;i<len;i++)
    {
        int id=str[i]-'a';
        if(temp->next[id]==NULL)
            return false;
        temp=temp->next[id];
    }
    return temp->endmark;
}
void del(node *cur)
{
    for(int i=0;i<26;i++)
    {
        if(cur->next[i])
            del(cur->next[i]);
    }
    delete (cur);
}
int main()
{
    puts("ENTER NUMBER OF WORDS");
    root = new node();
    int num_word;
    cin >> num_word;
    for (int i = 1; i <= num_word; i++) {
        char str[50];
        scanf("%s", str);
        insert(str, strlen(str));
    }
    puts("ENTER NUMBER OF QUERY");
    int query;
    cin >> query;
    for (int i = 1; i <= query; i++) {
        char str[50];
        scanf("%s", str);
        if (search(str, strlen(str)))
            puts("FOUND");
        else
            puts("NOT FOUND");
    }
    del(root);
    return 0;
}
