#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("identifier.txt","r",stdin);
    freopen("id.txt","w",stdout);
    /*map<string,int>mp;
    mp["return"]=1,mp["long"]=1;
    mp["auto"]=1,mp["register"]=1;
    mp["break"]=1,mp["static"]=1;
    mp["case"]=1,mp["unsigned"]=1;
    mp["char"]=1,mp["goto"]=1;
    mp["int"]=1,mp["else"]=1;
    mp["double"]=1,mp["if"]=1;
    mp["float"]=1,mp["switch"]=1;
    mp["continue"]=1,mp["for"]=1;
    mp["do"]=1,mp["extern"]=1;
    mp["while"]=1,mp["enum"]=1;
    mp["default"]=1,mp["const"]=1;
    mp["signed"]=1,mp["union"]=1;
    mp["typedef"]=1,mp["sizeof"];
    mp["short"]=1,mp["void"]=1;
    mp["union"],mp["struct"]=1,mp["volatile"]=1;
    string ch;
    while(cin>>ch)
    {
        string s;
        bool t=1;
        if(!(mp.find(ch)!=mp.end()))
        {
            if((ch[0]>='a'&&ch[0]<='z')||(ch[0]>='A'&&ch[0]<='Z')||ch[0]=='_')
            {
                for(int i=1; ch[i]!='\0'; i++)
                {
                    if((ch[i]>='a'&&ch[i]<='z')||(ch[i]>='A'&&ch[i]<='Z')||ch[i]=='_'||isdigit(ch[i]))
                        t=1;
                    else
                    {
                        t=0;
                        cout<<"Not a identifier\n";
                        break;
                    }
                }
                if(t)
                    cout<<"Identifier\n";
            }
            else
                cout<<"Not a identifier\n";
        }
        else
            cout<<"Not a identifier\n";

    }*/
    string ch;
    while(cin>>ch)
    {
        int l=ch.size();
        bool t=false;
        if(ch[0]=='$'&&l>=3&&ch[l-1]=='#')
        {
            l--;
            for(int i=1;i<l;i++)
            {
                if(isdigit(ch[i]))
                {
                    t=true;
                    break;
                }
            }
        }
        if(t)
            cout<<"Identifier\n";
        else
            cout<<"No\n";
    }
    return 0;
}
