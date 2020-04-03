#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("keyword.txt","r",stdin);
    freopen("keyO.txt","w",stdout);
    map<string,int>mp;
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
    mp["struct"]=1,mp["volatile"]=1;
    char ch;
    string s;
    while(scanf("%c",&ch)!=EOF)
    {
        if(isupper(ch)||islower(ch)||ispunct(ch)||isdigit(ch))
            s.push_back(ch);
        if(ch=='\n'||ch==' ')
        {
            if(mp.find(s)!=mp.end())
                cout<<"keyword\n";
            else
                cout<<"Not a keyword\n";
            s.clear();
        }
    }
    if(!s.empty())
    {
        if(mp.find(s)!=mp.end())
            cout<<"keyword\n";
        else
            cout<<"Not a keyword\n";
    }
    return 0;
}

