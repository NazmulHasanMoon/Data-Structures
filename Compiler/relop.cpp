#include<bits/stdc++.h>
using namespace std;
#define sf scanf
int main()
{
    freopen("relop.txt","r",stdin);
    freopen("relopO.txt","w",stdout);
    char ch;
    while(sf("%c",&ch)!=EOF)
    {
        if(ch=='<')
        {
            sf("%c",&ch);
            if(ch=='=')
                cout<<"LE\n";
            else if(ch=='>')
                cout<<"NE\n";
            else
                cout<<"LT\n";
            if(ch==EOF)
                break;
        }
        else if(ch=='=')
            cout<<"EQ\n";
        else if(ch=='>')
        {
            sf("%c",&ch);
            if(ch=='=')
                cout<<"GE\n";
            else
                cout<<"GT\n";
            if(ch==EOF)
                break;
        }
    }
    return 0;
}
