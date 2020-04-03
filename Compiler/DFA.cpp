#include<bits/stdc++.h>
using namespace std;
string ch;
bool t,tt;
int i,j;
void check()
{
    for(j=i+1; ch[j]!='\0'; j++)
    {
        if(ch[j]=='a')
            continue;
        else if(ch[j-1]=='a'&&ch[j]=='b'&&ch[j+1]=='b')
            t=1,j++;
    }
}
int main()
{
    freopen("DFAI.txt","r",stdin);
    freopen("dfaO.txt","w",stdout);

    while(cin>>ch)
    {
        t=0;
        for(i=0; ch[i]!='\0'; i++)
        {
            if(ch[i]=='a')
            {
                check();
                i=j-1;
            }
            else if(ch[i]=='b')
            {
                check();
                i=j-1;
            }
            else
                break;
        }
        if(t)
            cout<<"True\n";
        else
            cout<<"False\n";
    }
    return 0;
}
